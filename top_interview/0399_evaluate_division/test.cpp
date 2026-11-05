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

{ vector<vector<string>> eq{{"a","b"},{"b","c"}}; vector<double> val{2.0,3.0}; vector<vector<string>> q{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}}; auto got = s.calcEquation(eq, val, q); vector<double> want{6.0,0.5,-1.0,1.0,-1.0}; bool ok = got.size() == want.size(); for (size_t i = 0; ok && i < got.size(); ++i) ok = fabs(got[i] - want[i]) < 1e-5; check(ok, "example 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
