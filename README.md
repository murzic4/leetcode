# LeetCode Solutions (C++)

Solutions to the first LeetCode problems in C++17, each with example-based tests.

## Repository structure

```
leetcode/
├── 0001_two_sum/
│   ├── problem.md   # problem statement, signature, examples
│   ├── solution.h   # class Solution with the method to implement
│   ├── test.cpp     # tests from the examples + minimal runner
│   └── Makefile     # builds and runs the tests
├── 0002_add_two_numbers/
├── ...
├── 0010_regular_expression_matching/
└── parallel/                  # C++ parallel programming exercises
    ├── 01_thread_safe_counter/
    ├── 02_producer_consumer/
    └── ...
```

Each problem folder is self-contained.

- `problem.md` — problem statement, method signature and examples (as on LeetCode).
- `solution.h` — `class Solution` with the method stub marked `// TODO: implement`.
- `test.cpp` — test cases from the examples; prints `[PASS]`/`[FAIL]` and a final summary.
- `Makefile` — builds and runs the tests.

## Conventions

- LeetCode-style `class Solution` signatures (copy-paste ready for the site).
- `#pragma once` in headers.
- C++17, compiled with `g++`.
- No external test framework — each `test.cpp` has a tiny self-contained runner.

## How to run

```bash
cd 0001_two_sum
make test     # build + run tests + print result
make clean    # remove the test binary
```

Tests fail (non-zero exit) until the function is implemented — that is expected.

## Problems

| # | Folder | Problem | Method signature | Status |
|---|--------|---------|------------------|--------|
| 1 | `0001_two_sum` | Two Sum | `vector<int> twoSum(vector<int>&, int)` | solved |
| 2 | `0002_add_two_numbers` | Add Two Numbers | `ListNode* addTwoNumbers(ListNode*, ListNode*)` | solved |
| 3 | `0003_longest_substring_without_repeating_characters` | Longest Substring Without Repeating Characters | `int lengthOfLongestSubstring(string)` | solved |
| 4 | `0004_median_of_two_sorted_arrays` | Median of Two Sorted Arrays | `double findMedianSortedArrays(vector<int>&, vector<int>&)` | solved |
| 5 | `0005_longest_palindromic_substring` | Longest Palindromic Substring | `string longestPalindrome(string)` | solved |
| 6 | `0006_zigzag_conversion` | Zigzag Conversion | `string convert(string, int)` | solved |
| 7 | `0007_reverse_integer` | Reverse Integer | `int reverse(int)` | solved |
| 8 | `0008_string_to_integer_atoi` | String to Integer (atoi) | `int myAtoi(string)` | solved |
| 9 | `0009_palindrome_number` | Palindrome Number | `bool isPalindrome(int)` | solved |
| 10 | `0010_regular_expression_matching` | Regular Expression Matching | `bool isMatch(string, string)` | solved |
| 11 | `0011_container_with_most_water` | Container With Most Water | `int maxArea(vector<int>&)` | stub |
| 12 | `0012_integer_to_roman` | Integer to Roman | `string intToRoman(int)` | stub |
| 13 | `0013_roman_to_integer` | Roman to Integer | `int romanToInt(string)` | stub |
| 14 | `0014_longest_common_prefix` | Longest Common Prefix | `string longestCommonPrefix(vector<string>&)` | stub |
| 15 | `0015_3sum` | 3Sum | `vector<vector<int>> threeSum(vector<int>&)` | stub |
| 16 | `0016_3sum_closest` | 3Sum Closest | `int threeSumClosest(vector<int>&, int)` | stub |
| 17 | `0017_letter_combinations_of_a_phone_number` | Letter Combinations of a Phone Number | `vector<string> letterCombinations(string)` | stub |
| 18 | `0018_4sum` | 4Sum | `vector<vector<int>> fourSum(vector<int>&, int)` | stub |
| 19 | `0019_remove_nth_node_from_end_of_list` | Remove Nth Node From End of List | `ListNode* removeNthFromEnd(ListNode*, int)` | stub |
| 20 | `0020_valid_parentheses` | Valid Parentheses | `bool isValid(string)` | stub |

## Parallel Programming (C++)

A separate block of exercises on C++17 concurrency. Each task is a self-contained
folder under `parallel/` with the same layout (`problem.md`, `solution.h`, `test.cpp`,
`Makefile`) but compiled with `-pthread`.

Run them from the repo root with `make test` (runs both blocks), or individually:

```bash
cd parallel/01_thread_safe_counter
make test
```

| # | Folder | Task | Interface | Status |
|---|--------|------|-----------|--------|
| 1 | `01_thread_safe_counter` | Thread-safe counter (mutex vs atomic) | `MutexCounter` / `AtomicCounter` | solved |
| 2 | `02_producer_consumer` | Producer-consumer (bounded queue) | `BoundedQueue` | stub |
| 3 | `03_thread_pool` | Thread pool | `ThreadPool` | stub |
| 4 | `04_parallel_reduce` | Parallel sum (reduce) | `parallelSum(...)` | stub |
| 5 | `05_read_write_lock` | Read-write lock (`shared_mutex`) | `ReadWriteLockDemo` | stub |
| 6 | `06_two_thread_alternate` | Alternating output of two threads | `alternatePrint(...)` | stub |
| 7 | `07_dining_philosophers` | Dining philosophers | `DiningPhilosophers` | stub |
