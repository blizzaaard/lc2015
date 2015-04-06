// #112 Path Sum
//
// Given a binary tree and a sum, determine if the tree has a root-to-leaf path
// such that adding up all the values along the path equals the given sum.
//
// For example:
//
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
//
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

  public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root) {
            return false;
        } else {
            int left = sum - root->val;
            if (!root->left && !root->right) {
                return 0 == left;
            }
            return hasPathSum(root->left,  left)
                || hasPathSum(root->right, left);
        }
    }
};

int main()
{
    Solution s;
    {
        TreeNode node5(5);   TreeNode node4(4);   TreeNode node8(8);
        TreeNode node11(11); TreeNode node13(13); TreeNode node4a(4);
        TreeNode node7(7);   TreeNode node2(2);   TreeNode node1(1);
        node5.left = &node4;  node5.right = &node8;
        node4.left = &node11; node8.left  = &node13; node8.right = &node4;
        node11.left = &node7; node11.right = &node2; node4a.right = &node1;
        std::cout << s.hasPathSum(&node5, 22) << std::endl;
    }
    return 0;
}
