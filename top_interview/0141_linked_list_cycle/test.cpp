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

static ListNode* makeList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    Solution s;

{ ListNode* a = makeList({3,2,0,-4}); ListNode* t = a; while (t->next) t = t->next; t->next = a; check(s.hasCycle(a) == true, "cycle -> true"); }
    { ListNode* a = makeList({1,2}); check(s.hasCycle(a) == false, "no cycle -> false"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
