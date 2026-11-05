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

{ vector<int> v{1, 1, 2}; int k = s.removeDuplicates(v); check(k == 2 && vector<int>(v.begin(), v.begin() + k) == vector<int>{1, 2}, "nums = [1,1,2] -> 2"); }
    { vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; int k = s.removeDuplicates(v); check(k == 5 && vector<int>(v.begin(), v.begin() + k) == vector<int>{0, 1, 2, 3, 4}, "nums = [0,0,1,1,1,2,2,3,3,4] -> 5"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
