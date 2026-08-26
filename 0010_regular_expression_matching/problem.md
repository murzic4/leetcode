# 10. Regular Expression Matching

Given an input string `s` and a pattern `p`, implement regular expression matching with support for `'.'` and `'*'` where:

- `'.'` matches any single character.
- `'*'` matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

## Signature

```cpp
bool isMatch(string s, string p)
```

## Examples

**Example 1:**

- Input: `s = "aa"`, `p = "a"`
- Output: `false`

**Example 2:**

- Input: `s = "aa"`, `p = "a*"`
- Output: `true`

**Example 3:**

- Input: `s = "ab"`, `p = ".*"`
- Output: `true`
