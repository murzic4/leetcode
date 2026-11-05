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

{ vector<vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,60}}; check(s.searchMatrix(m, 3) == true, "target = 3 -> true"); }
    { vector<vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,60}}; check(s.searchMatrix(m, 13) == false, "target = 13 -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
