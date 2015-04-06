// #92 Reverse Linked List II
//
// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
// For example:
//
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
// return 1->4->3->2->5->NULL.
//
// Note:
//
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

  public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m == n) {
            return head;
        }

        // *start
        // +----+   +----+           +----+           +----+
        // |    |-->|    |--> ... -->|    |--> ... -->|    |
        // +----+   +----+           +----+           +----+
        //
        //          +---- (m, m + n) -----+

        ListNode **start = &head;
        int startPos = 1;
        for (; startPos < m; ++startPos) {
            start = &(*start)->next;
        }
        ListNode *prev = *start;
        if (!prev) {
            return head;
        }

        ListNode *curr = prev->next;
        ListNode *next = 0;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            if (++startPos == n) {
                break;
            }
            prev = curr;
            curr = next;
        }

        (*start)->next = next;
        *start = curr;

        return head;
    }
};

int main()
{
    Solution s;

    ListNode node1(3); ListNode node2(5);
    node1.next = &node2;

    s.reverseBetween(&node1, 1, 2);

    return 0;
}
