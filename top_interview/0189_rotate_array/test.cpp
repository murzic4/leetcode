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

{ vector<int> v{1, 2, 3, 4, 5, 6, 7}; s.rotate(v, 3); check(v == vector<int>{5, 6, 7, 1, 2, 3, 4}, "nums = [1,2,3,4,5,6,7], k = 3"); }
    { vector<int> v{-1, -100, 3, 99}; s.rotate(v, 2); check(v == vector<int>{3, 99, -1, -100}, "nums = [-1,-100,3,99], k = 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
