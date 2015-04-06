// #143 Reorder List
//
// Given a singly linked list L: L0->L1->...->Ln-1->Ln,
//
// reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
//
// You must do this in-place without altering the nodes' values.
//
// For example,
//
// Given {1,2,3,4}, reorder it to {1,4,2,3}.


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

    ListNode *getMid(ListNode *node)
    {
        if (!node || !node->next) {
            return node;
        }
        ListNode *p1 = node;
        ListNode *p2 = node;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }

    ListNode *reverse(ListNode *head)
    {
        if (!head) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        p->next = 0;
        while (q) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }

    ListNode *merge(ListNode *node1, ListNode *node2)
    {
        if (!node1 || node1 == node2) {
            return node2;
        }
        ListNode *head = node1;

        ListNode *node = node1;
        node1 = node1->next;

        bool right = true;
        while (node1 && node2) {
            if (right) {
                node->next = node2;
                node2 = node2->next;
            } else {
                node->next = node1;
                node1 = node1->next;
            }
            node = node->next;
            right = !right;
        }
        if (node1 && node != node1) {
            node->next = node1;
        }
        if (node2) {
            node->next = node2;
        }
        return head;
    }

  public:
    void reorderList(ListNode *head) {
        ListNode *mid = getMid(head);
        if (mid) {
            ListNode *p = reverse(mid->next);
            mid->next = 0;
            merge(head, p);
        }
    }
};


int main()
{
    Solution s;

    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4);
        node1.next = &node2; node2.next = &node3; node3.next = &node4;
        s.reorderList(&node1);
        print(&node1);
    }

    /*
     * Testing getMid()
    {
        ListNode *result = s.getMid(0);
        if (!result) {
            std::cout << "null" << std::endl;
        }
    }
    {
        ListNode node1(1);
        std::cout << s.getMid(&node1)->val << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2);
        node1.next = &node2;
        std::cout << s.getMid(&node1)->val << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3;
        std::cout << s.getMid(&node1)->val << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4;
        std::cout << s.getMid(&node1)->val << std::endl;
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4); ListNode node5(5);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4; node4.next = &node5;
        std::cout << s.getMid(&node1)->val << std::endl;
    }
    */

    /*
     * Testing reverse()
    {
        ListNode *result = s.reverse(0);
        if (!result) {
            std::cout << "null" << std::endl;
        }
    }
    {
        ListNode node1(1);
        print(s.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2);
        node1.next = &node2;
        print(s.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        node1.next = &node2; node2.next = &node3;
        print(s.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4;
        print(s.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4); ListNode node5(5);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4; node4.next = &node5;
        print(s.reverse(&node1));
    }
    */

    /*
     * Testing merge()
    std::cout << "Testing merge()" << std::endl;
    {
        ListNode node1(1);
        print(s.merge(&node1, 0));
    }
    {
        ListNode node2(2);
        print(s.merge(0, &node2));
    }
    {
        ListNode node1(1); ListNode node2(2);
        print(s.merge(&node1, &node2));
    }
    {
        ListNode node1(1); ListNode node2(2);
        node1.next = &node2;
        ListNode node3(3); ListNode node4(4);
        node3.next = &node4;
        print(s.merge(&node1, &node3));
    }
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4); ListNode node5(5);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4; node4.next = &node5;
        s.reorderList(&node1);
        print(&node1);
    }
    */

    return 0;
}
