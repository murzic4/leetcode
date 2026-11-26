#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#if 0
 class Solution {
public:
    ListNode* getMinimalIndex(const vector<ListNode*>& lists,
                              int& minimal_index) {
        ListNode* minimal = NULL;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];

            if (head == NULL) {
                continue;
            }

            if (minimal == NULL) {
                minimal = head;
                minimal_index = i;
                continue;
            }

            if (minimal->val > head->val) {
                minimal_index = i;
                minimal = head;
            }
        }

        return minimal;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto size = lists.size();

        ListNode* tail = NULL;
        ListNode* head = NULL;
        int index;

        while (ListNode* minimal = getMinimalIndex(lists, index)) {
            if (tail) {
                tail->next = minimal;
            }

            tail = minimal;
            lists[index] = minimal->next;
            tail->next = NULL;

            if (head == NULL) {
                head = tail;
            }
        }

        return head;
    }
};
#endif
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct cmp {
        bool operator()(const ListNode* l1, const ListNode* l2) const {
            return l1->val > l2->val;
        };
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy;
        ListNode* tail = &dummy;

        std::priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};