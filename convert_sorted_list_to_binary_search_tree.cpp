// #109 Convert Sorted List to Binary Search Tree
//
// Given a singly linked list where elements are sorted in ascending order,
// convert it to a height balanced BST.


#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *node)
{
    if (node) {
        print(node->left);
        std::cout << node->val << " ";
        print(node->right);
    }
}

class Solution {

    int getLength(ListNode *head)
    {
        int count = 0;
        while (head) {
            head = head->next;
            ++count;
        }
        return count;
    }

    TreeNode *helper(ListNode *& list, int start, int end)
    {
        if (start > end) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        TreeNode *left = helper(list, start, mid - 1);
        TreeNode *node = new TreeNode(list->val);
        node->left = left;
        list = list->next;
        node->right = helper(list, mid + 1, end);

        return node;
    }

  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return helper(head, 0, getLength(head) - 1);
    }
};

int main()
{
    Solution s;
    {
        ListNode node1(1); ListNode node2(2); ListNode node3(3);
        ListNode node4(4); ListNode node5(5);
        node1.next = &node2; node2.next = &node3;
        node3.next = &node4; node4.next = &node5;
        print(s.sortedListToBST(&node1));
        std::cout << std::endl;
    }
    return 0;
}
