#pragma once

#include <vector>
#include <algorithm>
#include <optional>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        const auto size = nums.size();
        const auto data = nums.data();
        std::optional<int> closest_sum;

        for (size_t i = 0; i + 2 < size; i++) {
            const int* left = data + i + 1;
            const int* right = data + size - 1;

            while (left < right) {
                int sum = data[i] + *left + *right;

                if (sum == target) {
                    closest_sum = target;
                    break;
                }

                if ((bool)closest_sum == false) {
                    closest_sum = sum;
                } else if (std::abs(target - *closest_sum) >
                           std::abs(target - sum)) {
                    closest_sum = sum;
                }

                if (sum  > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return *closest_sum;
                }
            }
        }

        return *closest_sum;
    }
};
