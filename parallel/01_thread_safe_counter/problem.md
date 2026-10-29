# 1. Thread-Safe Counter (mutex vs atomic)

Implement a counter that can be safely incremented from multiple threads.

Two variants are required, showing the two classic ways to protect shared state:

1. `MutexCounter` — guarded by a `std::mutex`.
2. `AtomicCounter` — built on `std::atomic<long long>`.

## Signature

```cpp
class MutexCounter {
public:
    void increment();
    long long get() const;
};

class AtomicCounter {
public:
    void increment();
    long long get() const;
};
```

Both methods must be thread-safe: `increment()` may be called concurrently from many
threads, and `get()` must return a consistent value.

## Examples

With `N` threads, each calling `increment()` `M` times, the final value of `get()`
must be exactly `N * M`.

For example, `8` threads × `100000` increments → `800000`.
