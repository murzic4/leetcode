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

    {
        vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        check(s.maxArea(height) == 49, "maxArea([1,8,6,2,5,4,8,3,7]) -> 49");
    }
    {
        vector<int> height = {1, 1};
        check(s.maxArea(height) == 1, "maxArea([1,1]) -> 1");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
