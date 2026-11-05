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

auto mk = [](const vector<string>& r) { vector<vector<char>> g; for (auto& s : r) g.push_back(vector<char>(s.begin(), s.end())); return g; };
    { auto g = mk({"11110","11010","11000","00000"}); check(s.numIslands(g) == 1, "example 1"); }
    { auto g = mk({"11000","11000","00100","00011"}); check(s.numIslands(g) == 3, "example 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
