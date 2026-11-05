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

{ vector<int> c{1,2,5}; check(s.coinChange(c, 11) == 3, "coins = [1,2,5], amount = 11 -> 3"); }
    { vector<int> c{2}; check(s.coinChange(c, 3) == -1, "coins = [2], amount = 3 -> -1"); }
    { vector<int> c{1}; check(s.coinChange(c, 0) == 0, "coins = [1], amount = 0 -> 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
