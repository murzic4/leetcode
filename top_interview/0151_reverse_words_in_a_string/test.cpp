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

check(s.reverseWords("the sky is blue") == "blue is sky the", "s = \"the sky is blue\" -> \"blue is sky the\"");
    check(s.reverseWords("  hello world  ") == "world hello", "s = \"  hello world  \" -> \"world hello\"");
    check(s.reverseWords("a good   example") == "example good a", "s = \"a good   example\" -> \"example good a\"");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
