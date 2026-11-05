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

{ vector<int> v{3,4,5,1,2}; check(s.findMin(v) == 1, "nums = [3,4,5,1,2] -> 1"); }
    { vector<int> v{4,5,6,7,0,1,2}; check(s.findMin(v) == 0, "nums = [4,5,6,7,0,1,2] -> 0"); }
    { vector<int> v{11,13,15,17}; check(s.findMin(v) == 11, "nums = [11,13,15,17] -> 11"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
