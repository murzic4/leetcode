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

{ vector<int> v{2,2,1}; check(s.singleNumber(v) == 1, "nums = [2,2,1] -> 1"); }
    { vector<int> v{4,1,2,1,2}; check(s.singleNumber(v) == 4, "nums = [4,1,2,1,2] -> 4"); }
    { vector<int> v{1}; check(s.singleNumber(v) == 1, "nums = [1] -> 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
