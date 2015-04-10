// #110 Balanced Binary Tree
//
// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int height(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int left  = height(root->left);
        int right = height(root->right);
        return (left > right ? left : right) + 1;
    }

  public:
    bool isBalanced(TreeNode *root)
    {
        if (!root) {
            return true;
        }

        int left  = height(root->left);
        int right = height(root->right);
        int diff  = left > right ? left - right : right - left;

        return diff <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);
    }
};

class Solution1 {
    bool helper(TreeNode *node, int *height)
    {
        if (!node) {
            *height = 0;
            return true;
        }
        int leftHeight = 0, rightHeight = 0;
        bool bLeft = helper(node->left, &leftHeight);
        bool bRight = helper(node->right, &rightHeight);
        *height = max(leftHeight, rightHeight) + 1;
        return bLeft && bRight && abs(leftHeight - rightHeight) < 2;
    }
public:
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return helper(root, &height);
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(3);  TreeNode node2(9); TreeNode node3(20);
        TreeNode node4(15); TreeNode node5(7);
        node1.left = &node2; node1.right = &node3;
        node3.left = &node4; node3.right = &node5;

        std::cout << s.isBalanced(&node1) << std::endl;
    }
    return 0;
}
