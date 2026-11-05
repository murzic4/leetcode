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

check(s.isPowerOfTwo(1) == true, "n = 1 -> true");
    check(s.isPowerOfTwo(16) == true, "n = 16 -> true");
    check(s.isPowerOfTwo(3) == false, "n = 3 -> false");
    check(s.isPowerOfTwo(0) == false, "n = 0 -> false");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
