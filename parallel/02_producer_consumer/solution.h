#pragma once

#include <cstddef>

class BoundedQueue {
public:
    explicit BoundedQueue(size_t capacity) {
        // TODO: implement (store capacity, init internals)
    }

    void push(int value) {
        // TODO: implement (block while full)
    }

    int pop() {
        // TODO: implement (block while empty)
        return 0;
    }
};
