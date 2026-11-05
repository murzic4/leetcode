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

auto mk = [](const vector<string>& rows) { vector<vector<char>> b; for (auto& r : rows) b.push_back(vector<char>(r.begin(), r.end())); return b; };
    { auto b = mk({"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"}); check(s.isValidSudoku(b) == true, "valid board -> true"); }
    { auto b = mk({"8........","..36.....",".7..9.2..",".5...7...","....457..","...1...3.","..1....68","..85...1.",".9....4.."}); check(s.isValidSudoku(b) == false, "invalid board -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
