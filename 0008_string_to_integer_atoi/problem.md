# 8. String to Integer (atoi)

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The algorithm for `myAtoi(string s)` is as follows:

1. Whitespace: ignore any leading whitespace (`" "`).
2. Signedness: determine the sign by checking if the next character is `'-'` or `'+'`. If neither is present, assume the number is positive.
3. Conversion: read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is `0`.
4. Rounding: if the integer is out of the 32-bit signed integer range `[-2^31, 2^31 - 1]`, round the integer to remain in the range (i.e. clamp to the boundary).

Return the integer as the final result.

## Signature

```cpp
int myAtoi(string s)
```

## Examples

**Example 1:**

- Input: `s = "42"`
- Output: `42`

**Example 2:**

- Input: `s = " -042"`
- Output: `-42`

**Example 3:**

- Input: `s = "1337c0d3"`
- Output: `1337`

**Example 4:**

- Input: `s = "0-1"`
- Output: `0`

**Example 5:**

- Input: `s = "words and 987"`
- Output: `0`
