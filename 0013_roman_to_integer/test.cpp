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

    check(s.romanToInt("III") == 3, "romanToInt(\"III\") -> 3");
    check(s.romanToInt("LVIII") == 58, "romanToInt(\"LVIII\") -> 58");
    check(s.romanToInt("MCMXCIV") == 1994, "romanToInt(\"MCMXCIV\") -> 1994");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
