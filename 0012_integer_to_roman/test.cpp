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

    check(s.intToRoman(3) == "III", "intToRoman(3) -> \"III\"");
    check(s.intToRoman(58) == "LVIII", "intToRoman(58) -> \"LVIII\"");
    check(s.intToRoman(1994) == "MCMXCIV", "intToRoman(1994) -> \"MCMXCIV\"");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
