# 12. Integer to Roman

Seven different symbols represent Roman numerals with the following values:

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest.

Given an integer, convert it to a Roman numeral.

## Signature

```cpp
string intToRoman(int num)
```

## Examples

**Example 1:**

- Input: `num = 3`
- Output: `"III"`

**Example 2:**

- Input: `num = 58`
- Output: `"LVIII"`

**Example 3:**

- Input: `num = 1994`
- Output: `"MCMXCIV"`
