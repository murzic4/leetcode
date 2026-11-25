#pragma once

#include <cstddef>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int size = 0;
    ListNode *original_head = head;
    ListNode *prev_head = NULL;

    while (head) {
      head = head->next;
      size++;
    }

    int skip = size - n;
    // printf("size %d\n", size);
    // printf("n %d\n", n);
    // printf("to skip %d\n", skip);

    head = original_head;
    while (skip--) {
      // printf("skip %d\n", head->val);
      prev_head = head;
      head = head->next;
    }

    // printf("after skip head = %d prev_head=%d\n", head->val, prev_head ?
    // prev_head->val: -1000);

    if (prev_head) {
      if (head->next) {
        prev_head->next = head->next;
      } else {
        prev_head->next = NULL;
      }
    } else {
      return head->next;
    }

    return original_head;
  }
};
