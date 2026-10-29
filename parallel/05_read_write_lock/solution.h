#pragma once

#include <utility>

class ReadWriteLockDemo {
public:
    void write(int value) {
        // TODO: implement (exclusive lock, a = b = value)
    }

    std::pair<int, int> read() const {
        // TODO: implement (shared lock, return {a, b})
        return {0, 0};
    }
};
