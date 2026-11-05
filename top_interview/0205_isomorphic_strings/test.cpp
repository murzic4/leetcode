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

check(s.isIsomorphic("egg", "add") == true, "\"egg\", \"add\" -> true");
    check(s.isIsomorphic("foo", "bar") == false, "\"foo\", \"bar\" -> false");
    check(s.isIsomorphic("paper", "title") == true, "\"paper\", \"title\" -> true");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
