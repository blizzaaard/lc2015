// #101 Symmetric Tree
//
// Given a binary tree, check whether it is a mirror of itself (ie, symmetric
// around its center).
//
// For example, this binary tree is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
// Note:
//
// Bonus points if you could solve it both recursively and iteratively.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    bool isSame(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 && !node2) {
            return true;
        } else if (node1 && node2 && node1->val == node2->val) {
            return isSame(node1->left,  node2->right)
                && isSame(node1->right, node2->left);
        } else {
            return false;
        }
    }

  public:
    bool isSymmetric(TreeNode *root)
    {
        return isSame(root, root);
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(1);
        TreeNode node2(2); TreeNode node3(2);
        TreeNode node4(3); TreeNode node5(4);
        TreeNode node6(4); TreeNode node7(3);
        node1.left = &node2; node1.right = &node3;
        node2.left = &node4; node2.right = &node5;
        node3.left = &node6; node3.right = &node7;
        std::cout << s.isSymmetric(&node1) << std::endl;
    }
    {
        TreeNode node1(1);
        TreeNode node2(2); TreeNode node3(2);
                           TreeNode node5(3);
                           TreeNode node7(3);
        node1.left = &node2; node1.right = &node3;
                             node2.right = &node5;
                             node3.right = &node7;
        std::cout << s.isSymmetric(&node1) << std::endl;
    }
    return 0;
}
