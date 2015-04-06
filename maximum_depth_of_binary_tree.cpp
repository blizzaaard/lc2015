// #104 Maximum Depth of Binary Tree
//
// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the
// root node down to the farthest leaf node.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

  public:
    int maxDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int left  = maxDepth(root->left);
        int right = maxDepth(root->right);
        return (left > right ? left : right) + 1;
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
        std::cout << s.maxDepth(&node1) << std::endl;
    }
    {
        TreeNode node1(1);  TreeNode node2(2);
        node1.left = &node2;
        std::cout << s.maxDepth(&node1) << std::endl;
    }
    return 0;
}
