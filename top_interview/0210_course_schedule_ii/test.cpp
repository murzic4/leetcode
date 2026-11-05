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

{ vector<vector<int>> p{{1,0}}; check(s.findOrder(2, p) == vector<int>{0,1}, "numCourses = 2, prerequisites = [[1,0]] -> [0,1]"); }
    { vector<vector<int>> p{}; check(s.findOrder(1, p) == vector<int>{0}, "numCourses = 1 -> [0]"); }
    { vector<vector<int>> p{{1,0},{0,1}}; check(s.findOrder(2, p).empty(), "cycle -> []"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
