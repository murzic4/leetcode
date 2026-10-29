#pragma once

#include <cstddef>
#include <functional>
#include <future>

class ThreadPool {
public:
    explicit ThreadPool(size_t num_threads) {
        // TODO: implement (start workers)
    }

    ~ThreadPool() {
        // TODO: implement (drain + join)
    }

    std::future<int> submit(std::function<int()> task) {
        // TODO: implement
        std::promise<int> p;
        p.set_value(0);
        return p.get_future();
    }
};
