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

{ vector<int> c{1,2,5}; check(s.change(5, c) == 4, "amount = 5, coins = [1,2,5] -> 4"); }
    { vector<int> c{2}; check(s.change(3, c) == 0, "amount = 3, coins = [2] -> 0"); }
    { vector<int> c{10}; check(s.change(10, c) == 1, "amount = 10, coins = [10] -> 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
