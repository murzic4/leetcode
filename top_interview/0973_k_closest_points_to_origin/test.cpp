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
    { vector<vector<int>> p{{1,3},{-2,2}}; check(norm(s.kClosest(p, 1)) == norm({{-2,2}}), "points = [[1,3],[-2,2]], k = 1 -> [[-2,2]]"); }
    { vector<vector<int>> p{{3,3},{5,-1},{-2,4}}; check(norm(s.kClosest(p, 2)) == norm({{3,3},{-2,4}}), "points = [[3,3],[5,-1],[-2,4]], k = 2 -> [[3,3],[-2,4]]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
