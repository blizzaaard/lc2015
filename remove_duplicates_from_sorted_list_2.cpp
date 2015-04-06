// #82 Remove Duplicates from Sorted List II
//
// Given a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list.
//
// For example,
//
// Given 1->2->3->3->4->4->5, return 1->2->5.
//
// Given 1->1->1->2->3, return 2->3.


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head)
{
    while (head) {
        std::cout << head->val << "(" << head << ")" << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

class Solution {

  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode **p = &head;
        while (*p) {
            ListNode **q = &(*p)->next;
            bool flag = false;
            while (*q && (*p)->val == (*q)->val) {
                ListNode *temp = *q;
                *q = (*q)->next;
                delete temp;
                flag = true;
            }
            if (flag) {
                ListNode *temp = *p;
                *p = *q;
                delete temp;
            } else {
                p = &(*p)->next;
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
        ListNode *node2 = new ListNode(2);
        ListNode *node3 = new ListNode(2);
        ListNode *node4 = new ListNode(3);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        print(s.deleteDuplicates(node1));
    }
    {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(1);
        node1->next = node2;
        print(s.deleteDuplicates(node1));
    }

    return 0;
}
