#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> values;
    values.reserve(nums.size());

    for (int idx = 0; idx < (int)nums.size(); idx++) {
      int current_val = nums[idx];
      int first_val = target - current_val;

      // Check if we already have first_val in the map:
      auto find_it = values.find(first_val);

      if (find_it == values.end()) {
        // noope: insert element in the values map if it is not faced yet
        find_it = values.find(current_val);
        if (find_it == values.end()) {
          values.emplace(current_val, idx);
        }
        continue;
      }

      // we have first_val
      return {find_it->second, idx};
    }
    return {0, 0};
  }
};