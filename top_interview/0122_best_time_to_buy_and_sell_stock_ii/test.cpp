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

{ vector<int> p{7, 1, 5, 3, 6, 4}; check(s.maxProfit(p) == 7, "prices = [7,1,5,3,6,4] -> 7"); }
    { vector<int> p{1, 2, 3, 4, 5}; check(s.maxProfit(p) == 4, "prices = [1,2,3,4,5] -> 4"); }
    { vector<int> p{7, 6, 4, 3, 1}; check(s.maxProfit(p) == 0, "prices = [7,6,4,3,1] -> 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
