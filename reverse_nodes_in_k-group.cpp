// #25 Reverse Nodes in k-Group
//
// Given a linked list, reverse the nodes of a linked list k at a time and
// return its modified list.
//
// If the number of nodes is not a multiple of k then left-out nodes in the end
// should remain as it is.
//
// You may not alter the values in the nodes, only nodes itself may be changed.
//
// Only constant memory is allowed.
//
// For example,
// Given this linked list: 1->2->3->4->5
//
// For k = 2, you should return: 2->1->4->3->5
//
// For k = 3, you should return: 3->2->1->4->5


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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode **pstart = &head;
        while (*pstart) {
            ListNode *end = *pstart;
            for (int i = 1; end && i < k; ++i) {
                end = end->next;
            }
            if (!end || *pstart == end) {
                break;
            }
            ListNode *p = *pstart;
            ListNode *q = p->next;
            while (q && p != end) {
                ListNode *r = q->next;
                q->next = p;
                p = q;
                q = r;
            }
            ListNode *last = *pstart;
            last->next = q;
            *pstart = end;
            pstart = &last->next;
        }
        return head;
    }
};

int main()
{
    ListNode node1(1), node2(2), node3(3);
    node1.next = &node2;
    node2.next = &node3;

    Solution s;
    print(s.reverseKGroup(&node1, 2));

    return 0;
}
