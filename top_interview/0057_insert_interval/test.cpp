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

{ vector<vector<int>> v{{1,3},{6,9}}; vector<int> ni{2,5}; check(s.insert(v, ni) == vector<vector<int>>{{1,5},{6,9}}, "example 1"); }
    { vector<vector<int>> v{{1,2},{3,5},{6,7},{8,10},{12,16}}; vector<int> ni{4,8}; check(s.insert(v, ni) == vector<vector<int>>{{1,2},{3,10},{12,16}}, "example 2"); }
    { vector<vector<int>> v{}; vector<int> ni{5,7}; check(s.insert(v, ni) == vector<vector<int>>{{5,7}}, "example 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
