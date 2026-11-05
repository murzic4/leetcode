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

auto norm = [](vector<vector<int>> g) { for (auto& v : g) sort(v.begin(), v.end()); sort(g.begin(), g.end()); return g; };
    { vector<int> c{2,3,6,7}; check(norm(s.combinationSum(c, 7)) == norm({{2,2,3},{7}}), "candidates = [2,3,6,7], target = 7"); }
    { vector<int> c{2,3,5}; check(norm(s.combinationSum(c, 8)) == norm({{2,2,2,2},{2,3,3},{3,5}}), "candidates = [2,3,5], target = 8"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
