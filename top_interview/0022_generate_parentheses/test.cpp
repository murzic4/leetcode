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

auto norm = [](vector<string> v) { sort(v.begin(), v.end()); return v; };
    { auto got = norm(s.generateParenthesis(3)); check(got == norm(vector<string>{"((()))","(()())","(())()","()(())","()()()"}), "n = 3"); }
    { auto got = norm(s.generateParenthesis(1)); check(got == norm(vector<string>{"()"}), "n = 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
