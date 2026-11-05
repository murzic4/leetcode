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

{ vector<int> v{2,3,-2,4}; check(s.maxProduct(v) == 6, "nums = [2,3,-2,4] -> 6"); }
    { vector<int> v{-2,0,-1}; check(s.maxProduct(v) == 0, "nums = [-2,0,-1] -> 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
