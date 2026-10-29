#pragma once

#include <atomic>
#include <mutex>

class MutexCounter {
public:
    void increment() {
        // TODO: implement (thread-safe)
    }

    long long get() const {
        // TODO: implement (thread-safe)
        return 0;
    }

private:
    std::mutex mtx_;
    long long value_ = 0;
};

class AtomicCounter {
public:
    void increment() {
        // TODO: implement (thread-safe)
    }

    long long get() const {
        // TODO: implement (thread-safe)
        return 0;
    }

private:
    std::atomic<long long> value_{0};
};
