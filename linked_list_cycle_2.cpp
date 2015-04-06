// #142 Linked List Cycle II
//
// Given a linked list, return the node where the cycle begins. If there is no
// cycle, return null.
//
// Follow up:
//
// Can you solve it without using extra space?


#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

  public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                while (head != q) {
                    head = head->next;
                    q    = q->next;
                }
                return head;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3;
        std::cout << s.detectCycle(&node1) << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3; node3.next = &node1;
        std::cout << s.detectCycle(&node1)->val << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3; node3.next = &node2;
        std::cout << s.detectCycle(&node1)->val << std::endl;
    }
    return 0;
}
