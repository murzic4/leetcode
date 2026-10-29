#include "solution.h"

#include <atomic>
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

int main() {
    const int K = 1000;
    const int readers = 4;

    ReadWriteLockDemo d;
    atomic<bool> torn{false};
    atomic<bool> done{false};

    thread writer([&]() {
        for (int v = 0; v < K; ++v) {
            d.write(v);
        }
        done = true;
    });

    vector<thread> readerThreads;
    readerThreads.reserve(readers);
    for (int r = 0; r < readers; ++r) {
        readerThreads.emplace_back([&]() {
            while (!done) {
                auto p = d.read();
                if (p.first != p.second) {
                    torn = true;
                }
            }
        });
    }

    writer.join();
    for (auto& t : readerThreads) {
        t.join();
    }

    check(!torn, "readers never observed a != b");

    auto final = d.read();
    check(final.first == K - 1 && final.second == K - 1,
          "final value is 999/999");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
