# 7. Dining Philosophers

Classic synchronization problem: `N` philosophers sit around a table with `N`
chopsticks (or forks). A philosopher must pick up two adjacent chopsticks to eat,
then puts them down.

Implement `run(philosophers, iterations)`:

- Spawn `philosophers` threads, each of which eats `iterations` times.
- A philosopher eats only when it holds both adjacent chopsticks.
- The function must terminate without deadlock for any `N` (for example via a
  global lock ordering, `try_lock` with backoff, or a single arbitration mutex).
- Return the total number of successful eats, which must equal
  `philosophers * iterations`.

## Signature

```cpp
class DiningPhilosophers {
public:
    int run(int philosophers, int iterations);
};
```

## Example

`run(5, 100)` → `500` (and must not hang).
