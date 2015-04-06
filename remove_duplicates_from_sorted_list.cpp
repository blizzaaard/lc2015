// #80 Remove Duplicates from Sorted List
//
// Given a sorted linked list, delete all duplicates such that each element
// appear only once.
//
// For example,
//
// Given 1->1->2, return 1->2.
//
// Given 1->1->2->3->3, return 1->2->3.


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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while (q) {
            if (q->val == p->val) {
                p->next = q->next;
                ListNode *temp = q;
                q = q->next;
                delete temp;
            } else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};

int main()
{
    Solution s;

    {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(2);
        node1->next = node2;
        node2->next = node3;
        print(s.deleteDuplicates(node1));
    }
    {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(1);
        ListNode *node3 = new ListNode(2);
        ListNode *node4 = new ListNode(3);
        ListNode *node5 = new ListNode(3);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        print(s.deleteDuplicates(node1));
    }
    return 0;
}
