# 3. Thread Pool

Implement a simple fixed-size thread pool.

- The constructor starts `num_threads` worker threads.
- Workers wait on a shared task queue (guarded by a mutex and a condition variable).
- `submit(std::function<int()>)` enqueues a task and returns a `std::future<int>`
  whose value is the task's return value.
- The destructor waits for all submitted tasks to finish, stops the workers, and
  joins them.

## Signature

```cpp
class ThreadPool {
public:
    explicit ThreadPool(size_t num_threads);
    ~ThreadPool();
    std::future<int> submit(std::function<int()> task);
};
```

## Example

With a pool of `4` threads and `64` tasks each returning `i * i`, the future for
task `i` must resolve to `i * i`.
