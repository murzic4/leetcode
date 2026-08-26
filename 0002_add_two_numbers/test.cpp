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
        ListNode* l1 = makeList({2, 4, 3});
        ListNode* l2 = makeList({5, 6, 4});
        vector<int> want = {7, 0, 8};
        check(toVector(s.addTwoNumbers(l1, l2)) == want,
              "addTwoNumbers([2,4,3], [5,6,4]) -> [7,0,8]");
    }
    {
        ListNode* l1 = makeList({0});
        ListNode* l2 = makeList({0});
        vector<int> want = {0};
        check(toVector(s.addTwoNumbers(l1, l2)) == want,
              "addTwoNumbers([0], [0]) -> [0]");
    }
    {
        ListNode* l1 = makeList({9, 9, 9, 9, 9, 9, 9});
        ListNode* l2 = makeList({9, 9, 9, 9});
        vector<int> want = {8, 9, 9, 9, 0, 0, 0, 1};
        check(toVector(s.addTwoNumbers(l1, l2)) == want,
              "addTwoNumbers([9,9,9,9,9,9,9], [9,9,9,9]) -> [8,9,9,9,0,0,0,1]");
    }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
