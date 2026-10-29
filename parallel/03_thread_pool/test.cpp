#include "solution.h"

#include <future>
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
    const int N = 64;
    ThreadPool pool(4);

    vector<future<int>> futures;
    futures.reserve(N);
    for (int i = 0; i < N; ++i) {
        futures.push_back(pool.submit([i]() { return i * i; }));
    }

    bool ok = true;
    for (int i = 0; i < N; ++i) {
        if (futures[i].get() != i * i) {
            ok = false;
        }
    }
    check(ok, "64 tasks return i*i on a 4-thread pool");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
