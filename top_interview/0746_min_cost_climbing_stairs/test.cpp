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

{ vector<int> c{10,15,20}; check(s.minCostClimbingStairs(c) == 15, "cost = [10,15,20] -> 15"); }
    { vector<int> c{1,100,1,1,1,100,1,1,100,1}; check(s.minCostClimbingStairs(c) == 6, "cost = [1,100,1,1,1,100,1,1,100,1] -> 6"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
