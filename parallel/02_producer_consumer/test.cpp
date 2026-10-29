#include "solution.h"

#include <algorithm>
#include <atomic>
#include <iostream>
#include <mutex>
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
    const int total = 1000;
    BoundedQueue q(4);

    vector<int> collected;
    mutex mtx;
    atomic<int> reserved{0};

    // Each consumer reserves one slot at a time and pops exactly one item,
    // so exactly `total` items are consumed overall.
    auto consumer = [&]() {
        while (true) {
            int idx = reserved.fetch_add(1);
            if (idx >= total) {
                break;
            }
            int v = q.pop();
            lock_guard<mutex> g(mtx);
            collected.push_back(v);
        }
    };

    thread p1([&]() {
        for (int i = 0; i < total / 2; ++i) q.push(i);
    });
    thread p2([&]() {
        for (int i = total / 2; i < total; ++i) q.push(i);
    });
    thread c1(consumer);
    thread c2(consumer);

    p1.join();
    p2.join();
    c1.join();
    c2.join();

    check(static_cast<int>(collected.size()) == total, "all 1000 items collected");

    sort(collected.begin(), collected.end());
    vector<int> want(total);
    for (int i = 0; i < total; ++i) {
        want[i] = i;
    }
    check(collected == want, "values 0..999 received exactly once");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
