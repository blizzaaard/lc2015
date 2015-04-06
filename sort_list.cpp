/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *head = 0;
        ListNode **p = &head;

        while (head1 && head2) {
            if (head1->val < head2->val) {
                *p = head1;
                head1 = head1->next;
            } else {
                *p = head2;
                head2 = head2->next;
            }
            p = &(*p)->next;
        }
        if (head1) {
            *p = head1;
        }
        if (head2) {
            *p = head2;
        }
        return head;
    }
    ListNode *sort(ListNode **node, int length)
    {
        if (1 == length) {
            ListNode *temp = *node;
            *node = (*node)->next;
            temp->next = 0;
            return temp;
        }
        
        ListNode *left  = sort(node, length / 2);
        ListNode *right = sort(node, length - length / 2);
        return merge(left, right);
    }
    ListNode *sortList(ListNode *head) {
        if (!head) {
            return 0;
        }
        int length = 0;
        ListNode *node = head;
        while (node) {
            ++length;
            node = node->next;
        }
        
        return sort(&head, length);
    }
};