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

{ vector<string> w{"foo", "bar"}; check(s.findSubstring("barfoothefoobarman", w) == vector<int>{0, 9}, "s = \"barfoothefoobarman\", words = [\"foo\",\"bar\"] -> [0,9]"); }
    { vector<string> w{"word", "good", "best", "word"}; check(s.findSubstring("wordgoodgoodgoodbestword", w).empty(), "no match -> []"); }
    { vector<string> w{"bar", "foo", "the"}; check(s.findSubstring("barfoofoobarthefoobarman", w) == vector<int>{6, 9, 12}, "s = \"barfoofoobarthefoobarman\" -> [6,9,12]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
