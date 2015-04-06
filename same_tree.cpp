// #100 Same Tree
//
// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical and
// the nodes have the same value.


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q) {
            return true;
        } else if (p && q && p->val == q->val) {
            return isSameTree(p->left,  q->left)
                && isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};

int main()
{
    Solution s;

    TreeNode nodeA1(1); TreeNode nodeA2(2); TreeNode nodeA3(3);
    TreeNode nodeB1(1); TreeNode nodeB2(2); TreeNode nodeB3(3);
    nodeA1.left = &nodeA2; nodeA1.right = &nodeA3;
    nodeB1.left = &nodeB2; nodeB1.right = &nodeB3;

    std::cout << s.isSameTree(&nodeA1, &nodeB1) << std::endl;
    return 0;
}
