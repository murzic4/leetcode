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

{ vector<int> v{10,9,2,5,3,7,101,18}; check(s.lengthOfLIS(v) == 4, "nums = [10,9,2,5,3,7,101,18] -> 4"); }
    { vector<int> v{0,1,0,3,2,3}; check(s.lengthOfLIS(v) == 4, "nums = [0,1,0,3,2,3] -> 4"); }
    { vector<int> v{7,7,7,7,7,7,7}; check(s.lengthOfLIS(v) == 1, "nums = [7,7,7,7,7,7,7] -> 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
