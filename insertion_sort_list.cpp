
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//class Solution {
//public:
//    ListNode *insertionSortList(ListNode *head) {
//        if (!head) {
//            return 0;
//        }
//        ListNode *node = head;
//        head = head->next;
//        node->next = 0;
//        while (head) {
//            ListNode **p = &node;
//            while (*p && head->val > (*p)->val) {
//                p = &(*p)->next;
//            }
//            ListNode *next = head->next;
//            head->next = *p;
//            *p = head;
//            head = next;
//        }
//        return node;
//    }
//};

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
    ListNode *insertionSortList(ListNode *node) {
        if (!node) return 0;
        ListNode *p = node->next;
        node->next = 0;
        while (p) {
            ListNode **pp = &node;
            while (*pp && (*pp)->val < p->val) {
                pp = &(*pp)->next;
            }
            ListNode *q = p->next;
            p->next = *pp;
            *pp = p;
            p = q;
        }
        return node;
    }
};

int main()
{
    ListNode node1(2); ListNode node2(5);
    ListNode node3(1); ListNode node4(3);
    ListNode node5(4);
    node1.next = &node2; node2.next = &node3;
    node3.next = &node4; node4.next = &node5;
    Solution s;
    print(s.insertionSortList(&node1));
    return 0;
}
