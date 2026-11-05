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

{ vector<int> v{1,3,-1,-3,5,3,6,7}; check(s.maxSlidingWindow(v, 3) == vector<int>{3,3,5,5,6,7}, "nums = [1,3,-1,-3,5,3,6,7], k = 3"); }
    { vector<int> v{1}; check(s.maxSlidingWindow(v, 1) == vector<int>{1}, "nums = [1], k = 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
