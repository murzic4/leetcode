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
        vector<int> nums = {-1, 2, 1, -4};
        check(s.threeSumClosest(nums, 1) == 2,
              "threeSumClosest([-1,2,1,-4], 1) -> 2");
    }
    {
        vector<int> nums = {0, 0, 0};
        check(s.threeSumClosest(nums, 1) == 0,
              "threeSumClosest([0,0,0], 1) -> 0");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
