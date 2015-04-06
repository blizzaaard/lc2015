// #2 Add Two Numbers
//
// You are given two linked lists representing two non-negative numbers. The
// digits are stored in reverse order and each of their nodes contain a single
// digit. Add the two numbers and return it as a linked list.
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode  *head  = 0;
        ListNode **p     = &head;
        int        carry = 0;
        while (l1 || l2) {
            ListNode *node = new ListNode(0);
            if (l1) {
                node->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                node->val += l2->val;
                l2 = l2->next;
            }
            node->val += carry;

            carry = node->val / 10;
            node->val %= 10;

            *p = node;
            p = &(*p)->next;
        }
        if (0 != carry) {
            *p = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(9), node3(9);
    node2.next = &node3;
    print(&node1);
    print(&node2);

    Solution s;
    print(s.addTwoNumbers(&node1, &node2));

    return 0;
}
