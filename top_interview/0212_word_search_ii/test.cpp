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
    auto norm = [](vector<string> v) { sort(v.begin(), v.end()); return v; };
    { auto b = mk({"oaan","etae","ihkr","iflv"}); vector<string> w{"oath","pea","eat","rain"}; check(norm(s.findWords(b, w)) == norm(vector<string>{"eat","oath"}), "example 1"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
