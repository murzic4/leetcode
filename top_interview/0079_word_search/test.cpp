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
    { auto b = mk({"ABCE","SFCS","ADEE"}); check(s.exist(b, "ABCCED") == true, "word = \"ABCCED\" -> true"); }
    { auto b = mk({"ABCE","SFCS","ADEE"}); check(s.exist(b, "SEE") == true, "word = \"SEE\" -> true"); }
    { auto b = mk({"ABCE","SFCS","ADEE"}); check(s.exist(b, "ABCB") == false, "word = \"ABCB\" -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
