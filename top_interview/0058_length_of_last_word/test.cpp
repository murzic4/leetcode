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

check(s.lengthOfLastWord("Hello World") == 5, "s = \"Hello World\" -> 5");
    check(s.lengthOfLastWord("   fly me   to   the moon  ") == 4, "s = \"   fly me   to   the moon  \" -> 4");
    check(s.lengthOfLastWord("luffy is still joyboy") == 6, "s = \"luffy is still joyboy\" -> 6");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
