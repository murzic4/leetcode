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

{ vector<int> v{2, 3, 1, 2, 4, 3}; check(s.minSubArrayLen(7, v) == 2, "target = 7, nums = [2,3,1,2,4,3] -> 2"); }
    { vector<int> v{1, 4, 4}; check(s.minSubArrayLen(4, v) == 1, "target = 4, nums = [1,4,4] -> 1"); }
    { vector<int> v{1, 1, 1, 1, 1, 1, 1, 1}; check(s.minSubArrayLen(11, v) == 0, "target = 11, nums = [1,1,1,1,1,1,1,1] -> 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
