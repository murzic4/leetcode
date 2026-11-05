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

{ vector<int> v{-2,1,-3,4,-1,2,1,-5,4}; check(s.maxSubArray(v) == 6, "nums = [-2,1,-3,4,-1,2,1,-5,4] -> 6"); }
    { vector<int> v{1}; check(s.maxSubArray(v) == 1, "nums = [1] -> 1"); }
    { vector<int> v{5,4,-1,7,8}; check(s.maxSubArray(v) == 23, "nums = [5,4,-1,7,8] -> 23"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
