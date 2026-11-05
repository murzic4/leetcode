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

{ vector<int> v{2,3,2}; check(s.rob(v) == 3, "nums = [2,3,2] -> 3"); }
    { vector<int> v{1,2,3,1}; check(s.rob(v) == 4, "nums = [1,2,3,1] -> 4"); }
    { vector<int> v{1,2,3}; check(s.rob(v) == 3, "nums = [1,2,3] -> 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
