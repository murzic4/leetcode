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

auto norm = [](vector<vector<string>> g) { for (auto& v : g) sort(v.begin(), v.end()); sort(g.begin(), g.end()); return g; };
    { vector<string> v{"eat","tea","tan","ate","nat","bat"}; check(norm(s.groupAnagrams(v)) == norm({{"bat"},{"nat","tan"},{"ate","eat","tea"}}), "example 1"); }
    { vector<string> v{""}; check(norm(s.groupAnagrams(v)) == norm({{""}}), "example 2"); }
    { vector<string> v{"a"}; check(norm(s.groupAnagrams(v)) == norm({{"a"}}), "example 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
