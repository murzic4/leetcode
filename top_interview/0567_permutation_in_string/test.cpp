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

check(s.checkInclusion("ab", "eidbaooo") == true, "s1 = \"ab\", s2 = \"eidbaooo\" -> true");
    check(s.checkInclusion("ab", "eidboaoo") == false, "s1 = \"ab\", s2 = \"eidboaoo\" -> false");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
