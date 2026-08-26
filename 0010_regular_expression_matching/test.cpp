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

    check(s.isMatch("aa", "a") == false, "isMatch(\"aa\", \"a\") -> false");
    check(s.isMatch("aa", "a*") == true, "isMatch(\"aa\", \"a*\") -> true");
    check(s.isMatch("ab", ".*") == true, "isMatch(\"ab\", \".*\") -> true");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
