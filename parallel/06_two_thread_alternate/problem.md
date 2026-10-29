# 6. Alternating Output of Two Threads

Coordinate two threads so that they produce the sequence `0, 1, 2, ..., count-1`
strictly in order, alternating between the threads:

- Thread A emits the even numbers `0, 2, 4, ...`
- Thread B emits the odd numbers `1, 3, 5, ...`

The threads must hand control back and forth (for example with a mutex and
condition variable, or two `std::binary_semaphore`s), so the output is always
sorted and has no gaps or duplicates.

## Signature

```cpp
std::vector<int> alternatePrint(int count);
```

## Examples

- `alternatePrint(10)` → `{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}`
- `alternatePrint(1)` → `{0}`
- `alternatePrint(0)` → `{}`
