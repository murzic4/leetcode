#pragma once

#include <optional>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        size_t nums1_size = nums1.size();
        size_t nums2_size = nums2.size();

        std::optional<int> median1_idx = (nums1_size + nums2_size) / 2;
        std::optional<int> median2_idx;

        if (((nums1_size + nums2_size) % 2) == 0) {
            median2_idx = median1_idx.value();
            median1_idx = median1_idx.value() - 1;
        }

        int median1_val = 0;
        int median2_val = 0;

        const int* p1 = nums1.data();
        const int* p2 = nums2.data();

        size_t nums1_idx = 0;
        size_t nums2_idx = 0;

        int result_idx = 0;

        while(nums1_idx < nums1_size || nums2_idx < nums2_size) {
            const int* v1 = (nums1_idx < nums1_size) ? p1 + nums1_idx : nullptr;
            const int* v2 = (nums2_idx < nums2_size) ? p2 + nums2_idx : nullptr;
            int v = 0;

            if (v1 && v2) {
                if (*v1 < *v2) {
                    v = *v1;
                    nums1_idx++;
                } else {
                    v = *v2;
                    nums2_idx++;
                }
            } else if (v1) {
                v = *v1;
                nums1_idx++;
            } else {
                v = *v2;
                nums2_idx++;
            }

            if (result_idx == median1_idx.value()) {
                median1_val = v;
                if (median2_idx.has_value() == false) {
                    break;
                }
            } 
            
            if (median2_idx.has_value() && result_idx == median2_idx.value()) {
                median2_val = v;
                break;
            }

            result_idx++;
        }

        double result = median2_idx.has_value() ? ((double)(median1_val + median2_val))/2 : median1_val;
        
        return result;
    }
};