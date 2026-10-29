#include "solution.h"

#include <iostream>
#include <string>
#include <thread>
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

template <typename Counter>
static long long runCounter(int threads, long long perThread) {
    Counter c;
    vector<thread> workers;
    workers.reserve(threads);
    for (int t = 0; t < threads; ++t) {
        workers.emplace_back([&c, perThread]() {
            for (long long i = 0; i < perThread; ++i) {
                c.increment();
            }
        });
    }
    for (auto& w : workers) {
        w.join();
    }
    return c.get();
}

int main() {
    const int threads = 8;
    const long long perThread = 100000;
    const long long want = static_cast<long long>(threads) * perThread;

    check(runCounter<MutexCounter>(threads, perThread) == want,
          "MutexCounter: 8 x 100000 increments");
    check(runCounter<AtomicCounter>(threads, perThread) == want,
          "AtomicCounter: 8 x 100000 increments");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
