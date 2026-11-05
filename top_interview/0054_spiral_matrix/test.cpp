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

{ vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}}; check(s.spiralOrder(m) == vector<int>{1,2,3,6,9,8,7,4,5}, "3x3"); }
    { vector<vector<int>> m{{1,2,3,4},{5,6,7,8},{9,10,11,12}}; check(s.spiralOrder(m) == vector<int>{1,2,3,4,8,12,11,10,9,5,6,7}, "3x4"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
