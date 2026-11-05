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

{ MinStack st; st.push(-2); st.push(0); st.push(-3); check(st.getMin() == -3, "getMin() -> -3"); st.pop(); check(st.top() == 0, "top() -> 0"); check(st.getMin() == -2, "getMin() -> -2"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
