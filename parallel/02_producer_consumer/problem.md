# 2. Producer-Consumer (bounded queue)

Implement a thread-safe bounded queue with blocking semantics, the classic
producer-consumer synchronization problem.

- `push(value)` blocks when the queue is full (capacity reached).
- `pop()` blocks when the queue is empty.
- Multiple producers and multiple consumers may run concurrently.

Use a `std::mutex` and `std::condition_variable`.

## Signature

```cpp
class BoundedQueue {
public:
    explicit BoundedQueue(size_t capacity);
    void push(int value);
    int pop();
};
```

## Example

With capacity `4`, two producers pushing `0..999` and two consumers popping all
`1000` values, every value must be received exactly once.

Producer A pushes `0..499`, producer B pushes `500..999`.
