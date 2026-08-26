#include "solution.h"

#include <iostream>
#include <string>

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

    check(s.lengthOfLongestSubstring("abcabcbb") == 3,
          "lengthOfLongestSubstring(\"abcabcbb\") -> 3");
    check(s.lengthOfLongestSubstring("bbbbb") == 1,
          "lengthOfLongestSubstring(\"bbbbb\") -> 1");
    check(s.lengthOfLongestSubstring("pwwkew") == 3,
          "lengthOfLongestSubstring(\"pwwkew\") -> 3");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
