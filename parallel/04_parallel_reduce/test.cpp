#include "solution.h"

#include <iostream>
#include <numeric>
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
    const int n = 1000000;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
    const long long want = static_cast<long long>(n) * (n - 1) / 2;

    check(parallelSum(data, 1) == want, "1 thread");
    check(parallelSum(data, 2) == want, "2 threads");
    check(parallelSum(data, 4) == want, "4 threads");
    check(parallelSum(data, 8) == want, "8 threads");

    check(parallelSum({}, 4) == 0, "empty vector");
    check(parallelSum({7}, 1) == 7, "single element");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
