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

{ vector<vector<int>> m{{1,2,3},{4,5,6},{7,8,9}}; s.rotate(m); check(m == vector<vector<int>>{{7,4,1},{8,5,2},{9,6,3}}, "3x3"); }
    { vector<vector<int>> m{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}; s.rotate(m); check(m == vector<vector<int>>{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}, "4x4"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
