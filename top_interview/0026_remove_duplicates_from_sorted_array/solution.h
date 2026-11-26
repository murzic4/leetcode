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
    int removeDuplicates(vector<int>& nums) {
        auto size = nums.size();
        int* data = nums.data();
        int write_idx = 0;
        int read_idx = 0;

        while (read_idx < size) {
            // printf("read_idx = %d write_idx = %d\n", read_idx, write_idx);
            if (data[write_idx] == data[read_idx]) {
                // printf("data[write_idx %d] (%d) == data[read_idx %d]  (%d) "
                //        "read_idx++ -> %d\n",
                //        write_idx, data[write_idx], read_idx, data[read_idx],
                //        read_idx + 1);
                read_idx++;
            } else {
                // printf("write_idx++ -> %d data[write_idx %d] (%d) = data[read_idx "
                //        "%d]  (%d) read_idx++ -> %d\n",
                //        write_idx + 1, write_idx, data[write_idx], read_idx,
                //        data[read_idx], read_idx + 1);
                write_idx++;
                data[write_idx] = data[read_idx];
                read_idx++;
            }
        }

        // printf("return write_idx++ %d\n", write_idx + 1);
        return write_idx + 1;
    }
};
