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

{ vector<vector<int>> t{{2},{3,4},{6,5,7},{4,1,8,3}}; check(s.minimumTotal(t) == 11, "triangle = [[2],[3,4],[6,5,7],[4,1,8,3]] -> 11"); }
    { vector<vector<int>> t{{-10}}; check(s.minimumTotal(t) == -10, "triangle = [[-10]] -> -10"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
