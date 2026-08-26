#include "solution.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static int passed = 0;
static int failed = 0;

static void check(bool ok, const string& name) {
    if (ok) {
        ++passed;
        cout << "[PASS] " << name << "\n";
    } else {
        ++failed;
        cout << "[FAIL] " << name << "\n";
    }
}

int main() {
    Solution s;

    {
        vector<int> nums1 = {1, 3};
        vector<int> nums2 = {2};
        check(s.findMedianSortedArrays(nums1, nums2) == 2.0,
              "findMedianSortedArrays([1,3], [2]) -> 2.0");
    }
    {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        check(s.findMedianSortedArrays(nums1, nums2) == 2.5,
              "findMedianSortedArrays([1,2], [3,4]) -> 2.5");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
