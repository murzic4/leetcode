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

{ WordDictionary d; d.addWord("bad"); d.addWord("dad"); d.addWord("mad"); check(d.search("pad") == false, "search(\"pad\") -> false"); check(d.search("bad") == true, "search(\"bad\") -> true"); check(d.search(".ad") == true, "search(\".ad\") -> true"); check(d.search("b..") == true, "search(\"b..\") -> true"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
