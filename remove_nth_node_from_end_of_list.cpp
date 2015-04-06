// #19 Remove Nth Node From End of List
//
// Given a linked list, remove the nth node from the end of list and return its
// head.
//
// For example,
//
//    Given linked list: 1->2->3->4->5, and n = 2.
//
//    After removing the second node from the end, the linked list becomes
//    1->2->3->5.
//
// Note:
//
// Given n will always be valid.
//
// Try to do this in one pass.


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *node)
{
    while (node) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

class Solution {

  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode **p = &head;
        ListNode **q = p;

        while (n > 0 && *q) {
            q = &(*q)->next;
            --n;
        }
        if (0 != n) {
            // Do not remove anything if we don't have n nodes in the list.

            return head;
        }
        while (*q) {
            q = &(*q)->next;
            p = &(*p)->next;
        }

        ListNode *temp = *p;
        *p = (*p)->next;
        delete temp;

        return head;
    }
};

int main()
{
    {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(4);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;

        Solution s;
        print(s.removeNthFromEnd(node1, 3));
    }
    {
        ListNode *node1 = new ListNode(1);
        Solution s;
        ListNode *result = s.removeNthFromEnd(node1, 1);
        if (!result) {
            std::cout << "OK" << std::endl;
        }
    }
    {
        Solution s;
        ListNode *result = s.removeNthFromEnd(0, 1);
        if (!result) {
            std::cout << "OK" << std::endl;
        }
    }

    return 0;
}
