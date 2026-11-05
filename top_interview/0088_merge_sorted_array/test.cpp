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

{ vector<int> a{1, 2, 3, 0, 0, 0}; vector<int> b{2, 5, 6}; s.merge(a, 3, b, 3); check(a == vector<int>{1, 2, 2, 3, 5, 6}, "nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3"); }
    { vector<int> a{1}; vector<int> b{}; s.merge(a, 1, b, 0); check(a == vector<int>{1}, "nums1 = [1], m = 1, nums2 = [], n = 0"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
