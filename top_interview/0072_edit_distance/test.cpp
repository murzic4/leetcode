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

check(s.minDistance("horse", "ros") == 3, "word1 = \"horse\", word2 = \"ros\" -> 3");
    check(s.minDistance("intention", "execution") == 5, "word1 = \"intention\", word2 = \"execution\" -> 5");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
