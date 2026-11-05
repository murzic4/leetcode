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

{ vector<int> p{3,6,7,11}; check(s.minEatingSpeed(p, 8) == 4, "piles = [3,6,7,11], h = 8 -> 4"); }
    { vector<int> p{30,11,23,4,20}; check(s.minEatingSpeed(p, 5) == 30, "piles = [30,11,23,4,20], h = 5 -> 30"); }
    { vector<int> p{30,11,23,4,20}; check(s.minEatingSpeed(p, 6) == 23, "piles = [30,11,23,4,20], h = 6 -> 23"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
