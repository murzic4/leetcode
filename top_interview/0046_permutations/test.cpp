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

auto norm = [](vector<vector<int>> g) { sort(g.begin(), g.end()); return g; };
    { vector<int> v{1,2,3}; check(norm(s.permute(v)) == norm({{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}}), "nums = [1,2,3]"); }
    { vector<int> v{0,1}; check(norm(s.permute(v)) == norm({{0,1},{1,0}}), "nums = [0,1]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
