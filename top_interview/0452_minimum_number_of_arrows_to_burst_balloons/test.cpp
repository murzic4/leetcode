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

{ vector<vector<int>> p{{10,16},{2,8},{1,6},{7,12}}; check(s.findMinArrowShots(p) == 2, "example 1"); }
    { vector<vector<int>> p{{1,2},{3,4},{5,6},{7,8}}; check(s.findMinArrowShots(p) == 4, "example 2"); }
    { vector<vector<int>> p{{1,2},{2,3},{3,4},{4,5}}; check(s.findMinArrowShots(p) == 2, "example 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
