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

{ vector<string> b{"AACCGGTA"}; check(s.minMutation("AACCGGTT","AACCGGTA",b) == 1, "example 1"); }
    { vector<string> b{"AACCGGTA","AACCGCTA","AAACGGTA"}; check(s.minMutation("AACCGGTT","AAACGGTA",b) == 2, "example 2"); }
    { vector<string> b{"AAAACCCC","AAACCCCC","AACCCCCC"}; check(s.minMutation("AAAAACCC","AACCCCCC",b) == 3, "example 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
