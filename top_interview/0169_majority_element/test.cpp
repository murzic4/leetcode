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

{ vector<int> v{3, 2, 3}; check(s.majorityElement(v) == 3, "nums = [3,2,3] -> 3"); }
    { vector<int> v{2, 2, 1, 1, 1, 2, 2}; check(s.majorityElement(v) == 2, "nums = [2,2,1,1,1,2,2] -> 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
