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

{ vector<int> v{3,0,1}; check(s.missingNumber(v) == 2, "nums = [3,0,1] -> 2"); }
    { vector<int> v{0,1}; check(s.missingNumber(v) == 2, "nums = [0,1] -> 2"); }
    { vector<int> v{9,6,4,2,3,5,7,0,1}; check(s.missingNumber(v) == 8, "nums = [9,6,4,2,3,5,7,0,1] -> 8"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
