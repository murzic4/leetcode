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

{ Trie t; t.insert("apple"); check(t.search("apple") == true, "search(\"apple\") -> true"); check(t.search("app") == false, "search(\"app\") -> false"); check(t.startsWith("app") == true, "startsWith(\"app\") -> true"); t.insert("app"); check(t.search("app") == true, "search(\"app\") -> true"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
