// #124 Binary Tree Maximum Path Sum
//
// Given a binary tree, find the maximum path sum.
//
// The path may start and end at any node in the tree.
//
// For example:
//
// Given the below binary tree,
//
//        1
//       / \
//      2   3
//
// Return 6.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int helper(int *currentMax, TreeNode *node)
    {
        if (!node) {
            return 0;
        }
        int left  = helper(currentMax, node->left);
        int right = helper(currentMax, node->right);

        int value = node->val;
        if (left > 0) {
            value += left;
        }
        if (right > 0) {
            value += right;
        }
        if (value > *currentMax) {
            *currentMax = value;
        }
        return std::max(0, std::max(left, right)) + node->val;
    }

  public:
    int maxPathSum(TreeNode *root)
    {
        int currentMax = INT_MIN;
        helper(&currentMax, root);
        return currentMax;
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
        node1.left = &node2; node1.right = &node3;
        std::cout << s.maxPathSum(&node1) << std::endl;
    }
    return 0;
}
