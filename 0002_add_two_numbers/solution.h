#pragma once

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool plus_one = false;
        ListNode* first = nullptr;
        ListNode* last_element = nullptr;
        ListNode* prev_element = nullptr;
        int iteration = 0;
        while (l1 || l2) {
            last_element = new ListNode(plus_one ? 1 : 0);
            plus_one = false;
            if (l1) {
                last_element->val += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                last_element->val += l2->val;
                l2 = l2->next;
            }

            if (last_element->val >= 10) {
                plus_one = true;
                last_element->val %= 10;
            }

            if (first == nullptr) {
                first = last_element;
                prev_element = last_element;

            } else {
                prev_element->next = last_element;
                prev_element = last_element;
            }
            iteration++;
        }

        if (plus_one) {
            if (first) {
                prev_element->next = new ListNode(plus_one ? 1 : 0);
            }
        }

        if (!first) {
            first = new ListNode(0);
        }

        return first;
    }
};