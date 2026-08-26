# 19. Remove Nth Node From End of List

Given the `head` of a linked list, remove the `n`-th node from the end of the list and return its head.

## Signature

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n)
```

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

## Examples

**Example 1:**

- Input: `head = [1,2,3,4,5]`, `n = 2`
- Output: `[1,2,3,5]`

**Example 2:**

- Input: `head = [1]`, `n = 1`
- Output: `[]`

**Example 3:**

- Input: `head = [1,2]`, `n = 1`
- Output: `[1]`
