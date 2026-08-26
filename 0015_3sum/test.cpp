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
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        auto got = s.threeSum(nums);
        vector<vector<int>> want = {{-1, -1, 2}, {-1, 0, 1}};
        normalize(got);
        normalize(want);
        check(got == want, "threeSum([-1,0,1,2,-1,-4]) -> [[-1,-1,2],[-1,0,1]]");
    }
    {
        vector<int> nums = {0, 1, 1};
        check(s.threeSum(nums).empty(), "threeSum([0,1,1]) -> []");
    }
    {
        vector<int> nums = {0, 0, 0};
        auto got = s.threeSum(nums);
        vector<vector<int>> want = {{0, 0, 0}};
        normalize(got);
        normalize(want);
        check(got == want, "threeSum([0,0,0]) -> [[0,0,0]]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
