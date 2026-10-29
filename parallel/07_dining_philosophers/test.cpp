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
    DiningPhilosophers d;

    check(d.run(5, 100) == 500, "5 philosophers x 100 iterations");
    check(d.run(3, 50) == 150, "3 philosophers x 50 iterations");
    check(d.run(7, 30) == 210, "7 philosophers x 30 iterations");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
