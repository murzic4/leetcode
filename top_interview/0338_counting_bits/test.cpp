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

check(s.countBits(2) == vector<int>{0,1,1}, "n = 2 -> [0,1,1]");
    check(s.countBits(5) == vector<int>{0,1,1,2,1,2}, "n = 5 -> [0,1,1,2,1,2]");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
