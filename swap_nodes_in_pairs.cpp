// #24 Swap Nodes in Pairs
//
// Given a linked list, swap every two adjacent nodes and return its head.
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
// Your algorithm should use only constant space. You may not modify the values
// in the list, only nodes itself can be changed.


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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode **p = 0, **q = &head, **r = 0;
        while (1) {
            p = q;
            if (!*p) {
                return head;
            }

            q = &(*p)->next;
            if (!*q) {
                return head;
            }

            r = &(*q)->next;

            //           +----(3)----+
            //           |           |
            //     +-----+(1)-----+  |
            //     |     |        |  |
            //     |     |  +-----+--+--(2)-+
            //     |     |  |     |  |      |
            //     |     v  |     v  |      v
            // +--+-+   +--+-+   +--+-+   +--+-+
            // |  | |-->|  | |-->|  | |-->|  | |
            // +--+-+   +--+-+   +--+-+   +--+-+
            //     *p       *q       *r
            //          temp

            ListNode *temp = *p;
            *p = *q;   // (1)
            *q = *r;   // (2)
            *r = temp; // (3)
        }
        return head;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    node1.next = &node2;

    Solution s;
    print(s.swapPairs(&node1));

    return 0;
}
