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
    {
        vector<int> want(10);
        for (int i = 0; i < 10; ++i) want[i] = i;
        check(alternatePrint(10) == want, "alternatePrint(10) -> 0..9");
    }
    check(alternatePrint(1) == vector<int>{0}, "alternatePrint(1) -> {0}");
    check(alternatePrint(0) == vector<int>{}, "alternatePrint(0) -> {}");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
