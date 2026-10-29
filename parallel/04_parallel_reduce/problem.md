# 4. Parallel Sum (reduce)

Compute the sum of an `int` vector in parallel.

Split the input into `num_threads` contiguous chunks, sum each chunk concurrently
(for example with `std::async` or `std::thread` + `std::accumulate`), then combine
the partial sums.

## Signature

```cpp
long long parallelSum(const std::vector<int>& data, int num_threads);
```

## Examples

- `parallelSum({}, 4)` → `0`
- `parallelSum({7}, 1)` → `7`
- `parallelSum(0..999999, 4)` → `499999500000`
