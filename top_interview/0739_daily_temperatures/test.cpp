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

{ vector<int> t{73,74,75,71,69,72,76,73}; check(s.dailyTemperatures(t) == vector<int>{1,1,4,2,1,1,0,0}, "example 1"); }
    { vector<int> t{30,40,50,60}; check(s.dailyTemperatures(t) == vector<int>{1,1,1,0}, "example 2"); }
    { vector<int> t{30,60,90}; check(s.dailyTemperatures(t) == vector<int>{1,1,0}, "example 3"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
