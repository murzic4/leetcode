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

auto norm = [](vector<int> v) { sort(v.begin(), v.end()); return v; };
    { vector<int> v{1,1,1,2,2,3}; check(norm(s.topKFrequent(v, 2)) == norm(vector<int>{1,2}), "nums = [1,1,1,2,2,3], k = 2 -> [1,2]"); }
    { vector<int> v{1}; check(norm(s.topKFrequent(v, 1)) == norm(vector<int>{1}), "nums = [1], k = 1 -> [1]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
