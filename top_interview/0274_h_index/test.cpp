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

{ vector<int> c{3, 0, 6, 1, 5}; check(s.hIndex(c) == 3, "citations = [3,0,6,1,5] -> 3"); }
    { vector<int> c{1, 3, 1}; check(s.hIndex(c) == 1, "citations = [1,3,1] -> 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
