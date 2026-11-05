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

{ vector<int> v{1,-2,3,-2}; check(s.maxSubarraySumCircular(v) == 3, "nums = [1,-2,3,-2] -> 3"); }
    { vector<int> v{5,-3,5}; check(s.maxSubarraySumCircular(v) == 10, "nums = [5,-3,5] -> 10"); }
    { vector<int> v{-3,-2,-3}; check(s.maxSubarraySumCircular(v) == -2, "nums = [-3,-2,-3] -> -2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
