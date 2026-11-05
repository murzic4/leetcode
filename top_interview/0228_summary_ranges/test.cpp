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

{ vector<int> v{0,1,2,4,5,7}; check(s.summaryRanges(v) == vector<string>{"0->2","4->5","7"}, "nums = [0,1,2,4,5,7]"); }
    { vector<int> v{0,2,3,4,6,8,9}; check(s.summaryRanges(v) == vector<string>{"0","2->4","6","8->9"}, "nums = [0,2,3,4,6,8,9]"); }
    { vector<int> v{}; check(s.summaryRanges(v).empty(), "nums = []"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
