#pragma once

#include <atomic>
#include <mutex>

class MutexCounter {
public:
    void increment() {
        // TODO: implement (thread-safe)
        const std::lock_guard<decltype(MutexCounter::mtx_)> guard(mtx_);
        value_++;
    }

    long long get() const {
        const std::lock_guard<decltype(MutexCounter::mtx_)> guard(mtx_);
        return value_;
    }

private:
    mutable std::mutex mtx_;
    long long value_ = 0;
};

class AtomicCounter {
public:
    void increment() {
        // TODO: implement (thread-safe)
        value_++;
    }

    long long get() const {
        // TODO: implement (thread-safe)
        return value_;
    }

private:
    std::atomic<long long> value_{0};
};
