#pragma once

#include <vector>
#include <algorithm>
#include <unordered_set>

struct Vec3Hash {
    std::size_t operator()(const std::vector<int>& v) const noexcept {
        std::size_t h = std::hash<int>{}(v[0]);
        auto combine = [&h](int x) {
            h ^= std::hash<int>{}(x) + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
        };
        combine(v[1]);
        combine(v[2]);
        return h;
    }
};

// std::unordered_set<std::vector<int>, Vec3Hash> s;

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::unordered_set<std::vector<int>, Vec3Hash> result_set;
        std::sort(nums.begin(), nums.end());

        const int* data = nums.data();
        size_t size = nums.size();

        // printf("size = %d\n", (int)size);

        for (size_t i = 0; i < size - 2; i++) {
            // printf("=============================================\n");
            // printf("i = %d\n", i);
            int val = data[i];
            const int* left = data + (i + 1);
            const int* right = data + (size - 1);

            // printf("val = %d\n", val);
            // printf("left = %d\n", *left);
            // printf("right = %d\n", *right);

            while (left < right) {
                // printf(" while iteration =============================================\n");
                int sum = val + *left + *right;
                if (sum > 0) {
                        right--;
                } else if (sum < 0) {
                        left++;
                } else {
                    // printf("---> storing resut %d %d %d\n", val, *left, *right);
                    std::vector<int> res = {val, *left, *right};
                    std::sort(res.begin(), res.end());

                    result_set.emplace(std::move(res));
                    while (left < right && *right == *(right - 1)) {
                        right--;
                        // printf("move similar right %d\n", *right);
                    }
                    while (left < right && *left == *(left + 1)) {
                        left++;
                        // printf("move similar left %d\n", *right);
                    }
    
                    left++;
                    right--;
                    // printf("left become %d\n", *left);
                    // printf("right become %d\n", *right);
                }
            }
        }

        for (const auto& val: result_set) {
            result.push_back(val);
        }

        return result;
    }
};