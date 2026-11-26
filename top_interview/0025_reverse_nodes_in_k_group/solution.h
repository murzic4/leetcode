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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::vector<ListNode*> buffer;
        ListNode dummy;
        ListNode* prev_tail = &dummy;

        buffer.reserve(k);

        if (k == 1) {
            return head;
        }


        while (head) {
            // printf("processing %d\n", head->val);
            // printf("push %d to buffer\n", head->val);
            buffer.push_back(head);

            head = head->next;
            
            if (buffer.size() == k) {
                // printf("buffer size %d\n", buffer.size());
                for (int j = k - 1; j > 0; j--) {
                    buffer[j]->next = buffer[j - 1];
                    // printf("%d -> %d\n", buffer[j]->val, buffer[j - 1]->val);
                }

                buffer[0]->next = NULL;
                // printf("ex first %d -> NULL\n", buffer[0]->val);
                prev_tail->next =  buffer[k - 1];
                // printf("prev_tail->next become %d\n", buffer[k - 1]->val);
                prev_tail = buffer[0];
                // printf("prev_tail become %d -> %s\n", buffer[0]->val);

                // printf("buffer.clear()\n");
                buffer.clear();
            }
        }

        if (buffer.size()) {
            prev_tail->next = buffer[0];
        }

        return dummy.next;
    }
};