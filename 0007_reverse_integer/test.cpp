#include "solution.h"

#include <iostream>
#include <string>

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

    check(s.reverse(123) == 321, "reverse(123) -> 321");
    check(s.reverse(-123) == -321, "reverse(-123) -> -321");
    check(s.reverse(120) == 21, "reverse(120) -> 21");
    check(s.reverse(0) == 0, "reverse(0) -> 0");
    check(s.reverse(1534236469) == 0, "reverse(1534236469) -> 0 (overflow)");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
