#include "solution.h"

#include <algorithm>
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

static void normalize(vector<vector<int>>& v) {
    for (auto& inner : v) {
        sort(inner.begin(), inner.end());
    }
    sort(v.begin(), v.end());
}

int main() {
    Solution s;

    {
        vector<int> nums = {1, 0, -1, 0, -2, 2};
        auto got = s.fourSum(nums, 0);
        vector<vector<int>> want = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
        normalize(got);
        normalize(want);
        check(got == want,
              "fourSum([1,0,-1,0,-2,2], 0) -> [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]");
    }
    {
        vector<int> nums = {2, 2, 2, 2, 2};
        auto got = s.fourSum(nums, 8);
        vector<vector<int>> want = {{2, 2, 2, 2}};
        normalize(got);
        normalize(want);
        check(got == want, "fourSum([2,2,2,2,2], 8) -> [[2,2,2,2]]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
