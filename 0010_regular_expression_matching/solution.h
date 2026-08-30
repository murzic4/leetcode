#pragma once

#include <string>
#include <vector>

class Solution {
public:
  bool isMatch(const std::string &s, const std::string &p) {
    auto s_len = s.size();
    auto p_len = p.size();
    //bool dp[s_len + 1][p_len + 1] = {{true, false}};
    std::vector<std::vector<bool>> dp(s_len + 1, std::vector<bool>(p_len + 1, false));
    dp[0][0] = true;

    for (size_t p_idx = 1; p_idx <= p_len; p_idx++) {
      if (p[p_idx - 1] == '*') {
        dp[0][p_idx] = dp[0][p_idx - 2];
      }
    }

    for (size_t s_idx = 1; s_idx <= s_len; s_idx++) {
      for (size_t p_idx = 1; p_idx <= p_len; p_idx++) {
        if (p[p_idx - 1] == '*') {
          dp[s_idx][p_idx] = dp[s_idx][p_idx - 2];

            if (s[s_idx - 1] == p[p_idx - 2] || p[p_idx - 2] == '.') {
                dp[s_idx][p_idx] = dp[s_idx][p_idx] || dp[s_idx - 1][p_idx];
            }
        } else {
          if (s[s_idx - 1] == p[p_idx - 1] || p[p_idx - 1] == '.') {
            dp[s_idx][p_idx] = dp[s_idx - 1][p_idx - 1];
          }
        }
      }
    }

    return dp[s_len][p_len];
  }
};
