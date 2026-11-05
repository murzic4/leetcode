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

check(s.wordPattern("abba", "dog cat cat dog") == true, "pattern = \"abba\" -> true");
    check(s.wordPattern("abba", "dog cat cat fish") == false, "pattern = \"abba\" -> false");
    check(s.wordPattern("aaaa", "dog cat cat dog") == false, "pattern = \"aaaa\" -> false");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
