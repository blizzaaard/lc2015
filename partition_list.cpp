// #86 Partition List
//
// Given a linked list and a value x, partition it such that all nodes less
// than x come before nodes greater than or equal to x.
//
// You should preserve the original relative order of the nodes in each of the
// two partitions.
//
// For example,
//
// Given 1->4->3->2->5->2 and x = 3,
//
// return 1->2->2->4->3->5.


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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *head1 = 0;
        ListNode *head2 = 0;

        ListNode **p = &head1;
        ListNode **q = &head2;

        // Split the items in the list into two lists.

        while (head) {
            if (head->val < x) {
                *p = head;
                p = &(*p)->next;
            } else {
                *q = head;
                q = &(*q)->next;
            }
            head = head->next;
        }

        // Connect the two lists together.

        *q = 0;
        *p = head2;

        return head1;
    }
};

int main()
{
    Solution s;
    {
        ListNode *node1 = new ListNode(1);
        ListNode *node2 = new ListNode(4);
        ListNode *node3 = new ListNode(3);
        ListNode *node4 = new ListNode(2);
        ListNode *node5 = new ListNode(5);
        ListNode *node6 = new ListNode(2);
        node1->next = node2;
        node2->next = node3;
        node3->next = node4;
        node4->next = node5;
        node5->next = node6;
        print(s.partition(node1, 3));
    }
    return 0;
}
