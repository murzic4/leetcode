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

    {
        vector<string> strs = {"flower", "flow", "flight"};
        check(s.longestCommonPrefix(strs) == "fl",
              "longestCommonPrefix([\"flower\",\"flow\",\"flight\"]) -> \"fl\"");
    }
    {
        vector<string> strs = {"dog", "racecar", "car"};
        check(s.longestCommonPrefix(strs) == "",
              "longestCommonPrefix([\"dog\",\"racecar\",\"car\"]) -> \"\"");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
