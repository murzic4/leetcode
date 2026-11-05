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

{ vector<int> v{1,2,2,3}; check(s.isMonotonic(v) == true, "nums = [1,2,2,3] -> true"); }
    { vector<int> v{6,5,4,4}; check(s.isMonotonic(v) == true, "nums = [6,5,4,4] -> true"); }
    { vector<int> v{1,3,2}; check(s.isMonotonic(v) == false, "nums = [1,3,2] -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
