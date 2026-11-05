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

{ vector<int> v{1,0,0,0,1,0,1}; check(s.maxDistToClosest(v) == 2, "seats = [1,0,0,0,1,0,1] -> 2"); }
    { vector<int> v{1,0,0,0}; check(s.maxDistToClosest(v) == 3, "seats = [1,0,0,0] -> 3"); }
    { vector<int> v{0,1}; check(s.maxDistToClosest(v) == 1, "seats = [0,1] -> 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
