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

{ vector<int> g{1, 2, 3, 4, 5}; vector<int> c{3, 4, 5, 1, 2}; check(s.canCompleteCircuit(g, c) == 3, "gas = [1,2,3,4,5], cost = [3,4,5,1,2] -> 3"); }
    { vector<int> g{2, 3, 4}; vector<int> c{3, 4, 3}; check(s.canCompleteCircuit(g, c) == -1, "gas = [2,3,4], cost = [3,4,3] -> -1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
