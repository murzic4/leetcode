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

{ vector<int> p{2,4,1}; check(s.maxProfit(2, p) == 2, "k = 2, prices = [2,4,1] -> 2"); }
    { vector<int> p{3,2,6,5,0,3}; check(s.maxProfit(2, p) == 7, "k = 2, prices = [3,2,6,5,0,3] -> 7"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
