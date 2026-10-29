# 5. Read-Write Lock

Implement a structure that allows many concurrent readers but gives writers
exclusive access, using `std::shared_mutex`.

The class keeps two fields `a` and `b` that must always be equal (the invariant
`a == b`):

- `write(value)` acquires an exclusive lock and sets `a = b = value`.
- `read()` acquires a shared lock and returns `{a, b}`.

Without proper locking, a reader could observe a moment where `a != b` (a "torn"
read) while a writer is mid-update.

## Signature

```cpp
class ReadWriteLockDemo {
public:
    void write(int value);
    std::pair<int, int> read() const;
};
```

## Example

A writer writes `0..999` in sequence while several reader threads repeatedly call
`read()`. Readers must never observe `a != b`, and after the writer finishes the
final `read()` must return `{999, 999}`.
