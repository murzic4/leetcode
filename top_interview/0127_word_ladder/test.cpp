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

{ vector<string> w{"hot","dot","dog","lot","log","cog"}; check(s.ladderLength("hit","cog",w) == 5, "example 1"); }
    { vector<string> w{"hot","dot","dog","lot","log"}; check(s.ladderLength("hit","cog",w) == 0, "example 2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
