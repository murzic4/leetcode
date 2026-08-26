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

    check(s.myAtoi("42") == 42, "myAtoi(\"42\") -> 42");
    check(s.myAtoi(" -042") == -42, "myAtoi(\" -042\") -> -42");
    check(s.myAtoi("1337c0d3") == 1337, "myAtoi(\"1337c0d3\") -> 1337");
    check(s.myAtoi("0-1") == 0, "myAtoi(\"0-1\") -> 0");
    check(s.myAtoi("words and 987") == 0, "myAtoi(\"words and 987\") -> 0");
    check(s.myAtoi("2147483646") == 2147483646, "myAtoi(\"2147483646\") -> 2147483646");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
