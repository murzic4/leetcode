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

    check(s.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR",
          "convert(\"PAYPALISHIRING\", 3) -> \"PAHNAPLSIIGYIR\"");
    check(s.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI",
          "convert(\"PAYPALISHIRING\", 4) -> \"PINALSIGYAHRPI\"");
    check(s.convert("A", 1) == "A", "convert(\"A\", 1) -> \"A\"");
    check(s.convert("AB", 1) == "AB", "convert(\"AB\", 1) -> \"AB\"");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
