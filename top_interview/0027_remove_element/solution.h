#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        auto size = nums.size();
        int read_idx = 0;
        int write_idx = 0;

        while (read_idx < size) {
            if (nums[read_idx] != val) {
                nums[write_idx] = nums[read_idx];
                write_idx++;
            }
            read_idx++;
        }
        return write_idx;
    }
};