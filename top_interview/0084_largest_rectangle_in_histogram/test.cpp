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

{ vector<int> h{2,1,5,6,2,3}; check(s.largestRectangleArea(h) == 10, "heights = [2,1,5,6,2,3] -> 10"); }
    { vector<int> h{2,4}; check(s.largestRectangleArea(h) == 4, "heights = [2,4] -> 4"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
