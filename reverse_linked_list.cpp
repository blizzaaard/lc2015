// Reverse Linked List


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

class Solution_Recursion {

  public:
    ListNode *reverse(ListNode *node)
    {
        if (!node) return node;
        if (node->next) {
            // if this is not the last node
            ListNode *head = reverse(node->next);
            node->next->next = node;
            node->next = 0;
            return head;
        } else {
            // no need to do any transformation for the last node.
            return node;
        }
    }
};

class Solution {

  public:
    ListNode *reverse(ListNode *head)
    {
        if (!head) return head;
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
};

int main()
{
    Solution_Recursion sr;
    {
        print(sr.reverse(0));
    }
    {
        ListNode node1(0);
        print(sr.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2);
        node1.next = &node2;
        print(sr.reverse(&node1));
    }
    {
        ListNode node1(1); ListNode node2(2);
        ListNode node3(3); ListNode node4(4);
        node1.next = &node2;
        node2.next = &node3;
        node3.next = &node4;
        print(sr.reverse(&node1));
    }

    Solution s;
    {
        print(s.reverse(0));
    }
    {
        ListNode node1(3); ListNode node2(5);
        node1.next = &node2;
        print(s.reverse(&node1));
    }

    return 0;
}
