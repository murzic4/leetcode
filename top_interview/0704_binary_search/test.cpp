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

{ vector<int> v{-1,0,3,5,9,12}; check(s.search(v, 9) == 4, "nums = [-1,0,3,5,9,12], target = 9 -> 4"); }
    { vector<int> v{-1,0,3,5,9,12}; check(s.search(v, 2) == -1, "nums = [-1,0,3,5,9,12], target = 2 -> -1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
