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

static vector<int> toVector(ListNode* head) {
    vector<int> out;
    while (head) {
        out.push_back(head->val);
        head = head->next;
    }
    return out;
}

int main() {
    Solution s;

    {
        ListNode* head = makeList({1, 2, 3, 4, 5});
        vector<int> want = {1, 2, 3, 5};
        check(toVector(s.removeNthFromEnd(head, 2)) == want,
              "removeNthFromEnd([1,2,3,4,5], 2) -> [1,2,3,5]");
    }
    {
        ListNode* head = makeList({1});
        check(toVector(s.removeNthFromEnd(head, 1)).empty(),
              "removeNthFromEnd([1], 1) -> []");
    }
    {
        ListNode* head = makeList({1, 2});
        vector<int> want = {1};
        check(toVector(s.removeNthFromEnd(head, 1)) == want,
              "removeNthFromEnd([1,2], 1) -> [1]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
