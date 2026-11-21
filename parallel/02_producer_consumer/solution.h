#pragma once

#include <condition_variable>
#include <cstddef>
#include <mutex>
#include <queue>

class BoundedQueue {
  std::queue<int> queue_;
  std::mutex mutex_;

  std::condition_variable not_full_;
  std::condition_variable not_empty_;

  int capacity_;

public:
  explicit BoundedQueue(size_t capacity) : capacity_(capacity) {}

  void push(int value) {
    std::unique_lock<std::mutex> lock(mutex_);

    not_full_.wait(lock, [this] { return queue_.size() < capacity_; });

    queue_.push(value);

    lock.unlock();
    not_empty_.notify_one();
  }

  int pop() {
    std::unique_lock<std::mutex> lock(mutex_);
    int result;

    not_empty_.wait(lock, [this] { return queue_.size() > 0; });

    result = queue_.front();
    queue_.pop();

    lock.unlock();

    not_full_.notify_one();
    return result;
  }
};
