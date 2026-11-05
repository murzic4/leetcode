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

{ vector<int> v{1,2,3,1}; check(s.containsDuplicate(v) == true, "nums = [1,2,3,1] -> true"); }
    { vector<int> v{1,2,3,4}; check(s.containsDuplicate(v) == false, "nums = [1,2,3,4] -> false"); }
    { vector<int> v{1,1,1,3,3,4,3,2,4,2}; check(s.containsDuplicate(v) == true, "nums = [1,1,1,3,3,4,3,2,4,2] -> true"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
