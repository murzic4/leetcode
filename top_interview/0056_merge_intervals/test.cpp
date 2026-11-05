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
    { vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}}; check(norm(s.merge(v)) == norm({{1,6},{8,10},{15,18}}), "example 1"); }
    { vector<vector<int>> v{{1,4},{4,5}}; check(norm(s.merge(v)) == norm({{1,5}}), "example 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
