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

{ vector<int> v{100,4,200,1,3,2}; check(s.longestConsecutive(v) == 4, "nums = [100,4,200,1,3,2] -> 4"); }
    { vector<int> v{0,3,7,2,5,8,4,6,0,1}; check(s.longestConsecutive(v) == 9, "nums = [0,3,7,2,5,8,4,6,0,1] -> 9"); }
    { vector<int> v{}; check(s.longestConsecutive(v) == 0, "nums = [] -> 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
