// #61 Rotate List
//
// Given a list, rotate the list to the right by k places, where k is
// non-negative.
//
// For example:
//
// Given 1->2->3->4->5->NULL and k = 2,
//
// return 4->5->1->2->3->NULL.


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {

  public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode **p    = &head;
        ListNode  *node = head;

        // Get the length of the list.

        int length = 0;
        while (*p) {
            node = *p;
            p    = &(*p)->next;
            ++length;
        }

        if (2 > length) {
            return head;
        }

        // Connect the tail to the head.

        node->next = head;

        // Find the new head.

        for (int i = 0; i < length - k % length; ++i) {
            node = node->next;
        }
        head = node->next;

        // Break the cycle.

        node->next = 0;

        return head;
    }
};

int main()
{
    ListNode node1(1); ListNode node2(2); ListNode node3(3);
    ListNode node4(4); ListNode node5(5);
    node1.next = &node2; node2.next = &node3;
    node3.next = &node4; node4.next = &node5;

    Solution s;
    print(s.rotateRight(&node1, 2));
    return 0;
}
