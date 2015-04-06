// #141 Linked List Cycle
//
// Given a linked list, determine if it has a cycle in it.
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
    bool hasCycle(ListNode *head)
    {
        ListNode *p = head;
        ListNode *q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3;
        std::cout << s.hasCycle(&node1) << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3; node3.next = &node1;
        std::cout << s.hasCycle(&node1) << std::endl;
    }
    return 0;
}
