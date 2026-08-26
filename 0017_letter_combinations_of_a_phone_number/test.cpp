#include "solution.h"

#include <algorithm>
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
        auto got = s.letterCombinations("23");
        vector<string> want = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
        sort(got.begin(), got.end());
        sort(want.begin(), want.end());
        check(got == want,
              "letterCombinations(\"23\") -> [ad,ae,af,bd,be,bf,cd,ce,cf]");
    }
    {
        check(s.letterCombinations("").empty(), "letterCombinations(\"\") -> []");
    }
    {
        auto got = s.letterCombinations("2");
        vector<string> want = {"a", "b", "c"};
        sort(got.begin(), got.end());
        sort(want.begin(), want.end());
        check(got == want, "letterCombinations(\"2\") -> [a,b,c]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
