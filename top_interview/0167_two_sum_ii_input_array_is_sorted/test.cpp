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

{ vector<int> v{2, 7, 11, 15}; check(s.twoSum(v, 9) == vector<int>{1, 2}, "numbers = [2,7,11,15], target = 9 -> [1,2]"); }
    { vector<int> v{2, 3, 4}; check(s.twoSum(v, 6) == vector<int>{1, 3}, "numbers = [2,3,4], target = 6 -> [1,3]"); }
    { vector<int> v{-1, 0}; check(s.twoSum(v, -1) == vector<int>{1, 2}, "numbers = [-1,0], target = -1 -> [1,2]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
