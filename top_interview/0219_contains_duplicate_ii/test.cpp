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

{ vector<int> v{1,2,3,1}; check(s.containsNearbyDuplicate(v, 3) == true, "nums = [1,2,3,1], k = 3 -> true"); }
    { vector<int> v{1,0,1,1}; check(s.containsNearbyDuplicate(v, 1) == true, "nums = [1,0,1,1], k = 1 -> true"); }
    { vector<int> v{1,2,3,1,2,3}; check(s.containsNearbyDuplicate(v, 2) == false, "nums = [1,2,3,1,2,3], k = 2 -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
