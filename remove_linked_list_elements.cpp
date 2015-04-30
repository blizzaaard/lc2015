// #203 Remove Linked List Elements
//
// Remove all elements from a linked list of integers that have value val.
//
// Example
//
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//
// Return: 1 --> 2 --> 3 --> 4 --> 5


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

  public:
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode **pp = &head;
        while (*pp) {
            ListNode *node = *pp;
            if (node->val == val) {
                *pp = node->next;
                delete node;
            } else {
                pp = &node->next;
            }
        }
        return head;
    }
};
