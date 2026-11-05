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

check(s.longestCommonSubsequence("abcde", "ace") == 3, "text1 = \"abcde\", text2 = \"ace\" -> 3");
    check(s.longestCommonSubsequence("abc", "abc") == 3, "same strings -> 3");
    check(s.longestCommonSubsequence("abc", "def") == 0, "no common -> 0");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
