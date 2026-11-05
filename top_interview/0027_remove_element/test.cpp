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

{ vector<int> v{3, 2, 2, 3}; int k = s.removeElement(v, 3); sort(v.begin(), v.begin() + k); check(k == 2 && vector<int>(v.begin(), v.begin() + k) == vector<int>{2, 2}, "nums = [3,2,2,3], val = 3 -> 2"); }
    { vector<int> v{0, 1, 2, 2, 3, 0, 4, 2}; int k = s.removeElement(v, 2); sort(v.begin(), v.begin() + k); check(k == 5 && vector<int>(v.begin(), v.begin() + k) == vector<int>{0, 0, 1, 3, 4}, "nums = [0,1,2,2,3,0,4,2], val = 2 -> 5"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
