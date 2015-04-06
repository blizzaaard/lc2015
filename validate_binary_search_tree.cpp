// #98 Validate Binary Search Tree
//
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
//  - The left subtree of a node contains only nodes with keys less than the
//    node's key.
//
//  - The right subtree of a node contains only nodes with keys greater than
//    the node's key.
//
//  - Both the left and right subtrees must also be binary search trees.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {

    bool helper(TreeNode *root, int *min, int *max)
        // Return 'true' if the value of the specified 'root' node is between
        // the specified '*min' and the specified '*max', and 'false'
        // otherwise.  Note that if 'min' is 0, there is no minimum limit, and
        // if 'max' is 0, there is no maximum limit.
    {
        if (!root) {
            return true;
        }
        if (min && root->val <= *min) {
            // There is a minimum bound and the current value is less than or
            // equals to the minimum bound, which does not satisfy the
            // requirement.

            return false;
        }
        if (max && root->val >= *max) {
            // There is a maximum bound and the current value is greater than
            // or equals to the maximum bound, which does not satisfy the
            // requirement.

            return false;
        }
        return helper(root->left, min, &root->val)
            && helper(root->right, &root->val, max);
    }

  public:
    bool isValidBST(TreeNode *root)
    {
        return helper(root, 0, 0);
    }
};

int main()
{
    {
        TreeNode node1(1); TreeNode node2(1);
        node1.left = &node2;
        Solution s;
        std::cout << s.isValidBST(&node1) << std::endl;
    }
    {
        TreeNode node1(INT_MIN); TreeNode node2(INT_MAX);
        node1.right = &node2;
        Solution s;
        std::cout << s.isValidBST(&node1) << std::endl;
    }
    return 0;
}
