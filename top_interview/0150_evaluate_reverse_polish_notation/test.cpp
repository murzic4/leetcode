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

{ vector<string> t{"2","1","+","3","*"}; check(s.evalRPN(t) == 9, "tokens = [\"2\",\"1\",\"+\",\"3\",\"*\"] -> 9"); }
    { vector<string> t{"4","13","5","/","+"}; check(s.evalRPN(t) == 6, "tokens = [\"4\",\"13\",\"5\",\"/\",\"+\"] -> 6"); }
    { vector<string> t{"10","6","9","3","+","-11","*","/","*","17","+","5","+"}; check(s.evalRPN(t) == 22, "long example -> 22"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
