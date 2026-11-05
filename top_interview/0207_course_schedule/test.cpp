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

{ vector<vector<int>> p{{1,0}}; check(s.canFinish(2, p) == true, "numCourses = 2, prerequisites = [[1,0]] -> true"); }
    { vector<vector<int>> p{{1,0},{0,1}}; check(s.canFinish(2, p) == false, "numCourses = 2, prerequisites = [[1,0],[0,1]] -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
