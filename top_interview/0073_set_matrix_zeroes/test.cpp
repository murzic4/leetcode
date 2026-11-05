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

{ vector<vector<int>> m{{1,1,1},{1,0,1},{1,1,1}}; s.setZeroes(m); check(m == vector<vector<int>>{{1,0,1},{0,0,0},{1,0,1}}, "example 1"); }
    { vector<vector<int>> m{{0,1,2,0},{3,4,5,2},{1,3,1,5}}; s.setZeroes(m); check(m == vector<vector<int>>{{0,0,0,0},{0,4,5,0},{0,3,1,0}}, "example 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
