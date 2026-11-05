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

{ vector<int> v{1, 2, 3, 4}; check(s.productExceptSelf(v) == vector<int>{24, 12, 8, 6}, "nums = [1,2,3,4] -> [24,12,8,6]"); }
    { vector<int> v{-1, 1, 0, -3, 3}; check(s.productExceptSelf(v) == vector<int>{0, 0, 9, 0, 0}, "nums = [-1,1,0,-3,3] -> [0,0,9,0,0]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
