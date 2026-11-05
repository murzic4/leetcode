# 30. Substring with Concatenation of All Words

Return all starting indices of substrings that are a concatenation of all words.

**Difficulty:** Hard · **Topic:** Sliding Window

**LeetCode:** https://leetcode.com/problems/substring_with_concatenation_of_all_words/

## Signature

```cpp
vector<int> findSubstring(string s, vector<string>& words)
```

## Examples

- s = "barfoothefoobarman", words = ["foo","bar"] -> [0,9]
- s = "barfoofoobarthefoobarman", words = ["bar","foo","the"] -> [6,9,12]
