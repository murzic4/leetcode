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
        vector<int> nums = {2, 7, 11, 15};
        vector<int> want = {0, 1};
        check(s.twoSum(nums, 9) == want, "twoSum([2,7,11,15], 9) -> [0,1]");
    }
    {
        vector<int> nums = {3, 2, 4};
        vector<int> want = {1, 2};
        check(s.twoSum(nums, 6) == want, "twoSum([3,2,4], 6) -> [1,2]");
    }
    {
        vector<int> nums = {3, 3};
        vector<int> want = {0, 1};
        check(s.twoSum(nums, 6) == want, "twoSum([3,3], 6) -> [0,1]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
