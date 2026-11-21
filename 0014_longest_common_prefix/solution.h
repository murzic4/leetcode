#pragma once

#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(const std::vector<std::string> &strs) {
    int ch_idx = 0;
    size_t size = strs.size();

    if (size == 1) {
      return strs[0];
    }

    while (strs[0][ch_idx] != '\0') {
      for (int i = 1; i < size; i++) {
        if (strs[i][ch_idx] == '\0' || strs[0][ch_idx] != strs[i][ch_idx]) {
          goto done;
        }
      }
      ch_idx++;
    }

  done:
    return strs[0].substr(0, ch_idx);
  }
};
