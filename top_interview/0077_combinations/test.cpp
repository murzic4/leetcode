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
    { check(norm(s.combine(4, 2)) == norm({{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}), "n = 4, k = 2"); }
    { check(norm(s.combine(1, 1)) == norm({{1}}), "n = 1, k = 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
