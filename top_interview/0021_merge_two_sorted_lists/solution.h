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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = NULL;
        ListNode* tail = NULL;

        while (list1 != NULL || list2 != NULL) {
            if (list1 != NULL && list2 != NULL) {
                // printf("Both list1 and list2 exists: list1 %d list2 %d\n",
                //        list1->val, list2->val);

                if (list1->val < list2->val) {
                    goto take_list1;

                } else {
                    goto take_list2;

                }
            } else if (list1 != NULL) {
                // printf("Only list1 exists: list1 %d \n", list1->val);
                goto take_list1;

            } else if (list2 != NULL) {
                // printf("Only list2 exists: list1 %d \n", list2->val);
                goto take_list2;
            }
        take_list1:
            // printf("Taking list1 %d\n", list1->val);
            if (tail) {
                tail->next = list1;
            }

            tail = list1;
            list1 = list1->next;
            tail->next = NULL;

            goto take_done;
        take_list2:
            // printf("Taking list1 %d\n", list2->val);
            if (tail) {
                tail->next = list2;
            }

            tail = list2;
            list2 = list2->next;
            tail->next = NULL;

            goto take_done;

        take_done:
            if (result == NULL) {
                result = tail;
            }

            // if (tail) {
            //     printf("NEW TAIL result %d\n", tail->val);
            // }

            // printf("=======================================\n");
            // {
            //     ListNode* new_result = result;

            //     while (new_result) {
            //         printf("= %d\n", new_result->val);
            //         new_result = new_result->next;
            //     }
            // }
            // printf("=======================================\n");
        }
        return result;
    }
};