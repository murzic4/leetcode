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

{ vector<int> v{2, 3, 1, 1, 4}; check(s.canJump(v) == true, "nums = [2,3,1,1,4] -> true"); }
    { vector<int> v{3, 2, 1, 0, 4}; check(s.canJump(v) == false, "nums = [3,2,1,0,4] -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
