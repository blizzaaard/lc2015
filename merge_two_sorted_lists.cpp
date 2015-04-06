// #21 Merge Two Sorted Lists
//
// Merge two sorted linked lists and return it as a new list. The new list
// should be made by splicing together the nodes of the first two lists.


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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode  *head = 0;
        ListNode **p    = &head;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                *p = l1;
                p  = &l1->next;
                l1 = l1->next;
            } else {
                *p = l2;
                p  = &l2->next;
                l2 = l2->next;
            }
        }
        if (l1) {
            *p = l1;
        }
        if (l2) {
            *p = l2;
        }
        return head;
    }
};

int main()
{
    {
        ListNode l1node1(1); ListNode l1node2(2); ListNode l1node3(3);
        l1node1.next = &l1node2; l1node2.next = &l1node3;

        ListNode l2node1(1); ListNode l2node2(2); ListNode l2node3(3);
        l2node1.next = &l2node2; l2node2.next = &l2node3;

        Solution s;
        print(s.mergeTwoLists(&l1node1, &l2node1));
    }

    {
        ListNode l1node1(1); ListNode l1node2(3); ListNode l1node3(5);
        l1node1.next = &l1node2; l1node2.next = &l1node3;

        ListNode l2node1(2); ListNode l2node2(4); ListNode l2node3(6);
        l2node1.next = &l2node2; l2node2.next = &l2node3;

        Solution s;
        print(s.mergeTwoLists(&l1node1, &l2node1));
    }

    {
        ListNode l1node1(1); ListNode l1node2(2); ListNode l1node3(3);
        l1node1.next = &l1node2; l1node2.next = &l1node3;

        ListNode l2node1(4); ListNode l2node2(5); ListNode l2node3(6);
        l2node1.next = &l2node2; l2node2.next = &l2node3;

        Solution s;
        print(s.mergeTwoLists(&l1node1, &l2node1));
    }

    {
        ListNode l1node1(4); ListNode l1node2(5); ListNode l1node3(6);
        l1node1.next = &l1node2; l1node2.next = &l1node3;

        ListNode l2node1(1); ListNode l2node2(2); ListNode l2node3(3);
        l2node1.next = &l2node2; l2node2.next = &l2node3;

        Solution s;
        print(s.mergeTwoLists(&l1node1, &l2node1));
    }

    return 0;
}
