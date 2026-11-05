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

{ LRUCache c(2); c.put(1, 1); c.put(2, 2); check(c.get(1) == 1, "get(1) -> 1"); c.put(3, 3); check(c.get(2) == -1, "get(2) -> -1 (evicted)"); c.put(4, 4); check(c.get(1) == -1 && c.get(3) == 3 && c.get(4) == 4, "eviction order"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
