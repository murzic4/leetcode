#pragma once

#include <vector>

class Solution {
public:
  int maxArea(const std::vector<int> &height) {
    int max = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
      int high = std::min(height[left], height[right]);
      int width = right - left;
      max = std::max(max, high * width);

      if (height[left] > height[right]) {
        right--;
      } else {
        left++;
      }
    }

    return max;
  }
};
