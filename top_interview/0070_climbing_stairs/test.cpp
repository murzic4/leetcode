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

check(s.climbStairs(2) == 2, "n = 2 -> 2");
    check(s.climbStairs(3) == 3, "n = 3 -> 3");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
