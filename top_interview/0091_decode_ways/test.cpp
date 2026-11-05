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

check(s.numDecodings("12") == 2, "s = \"12\" -> 2");
    check(s.numDecodings("226") == 3, "s = \"226\" -> 3");
    check(s.numDecodings("06") == 0, "s = \"06\" -> 0");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
