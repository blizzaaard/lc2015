// #99 Recover Binary Search Tree
//
// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
// Note:
//
// A solution using O(n) space is pretty straight forward. Could you devise a
// constant space solution?


#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *node)
{
    std::stack<TreeNode *> stack;
    while (node || !stack.empty()) {
        if (node) {
            stack.push(node);
            node = node->left;
        } else {
            node = stack.top();
            stack.pop();
            std::cout << node->val << " ";
            node = node->right;
        }
    }
    std::cout << std::endl;
}

class Solution {

  public:
    void recoverTree(TreeNode *node)
    {
        TreeNode *first  = 0;
        TreeNode *second = 0;
        TreeNode *prev   = 0;

        std::stack<TreeNode *> stack;
        while (node || !stack.empty()) {
            if (node) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();

                // - Find the first element
                //
                //      1 4 3 2 5
                //        | |
                //     prev node
                //
                //   prev > node, so first = prev
                //
                // - Find the second element
                //
                //      1 4 3 2 5
                //          | |
                //       prev node
                //
                //   prev > node, so second = node
                if (prev && prev->val > node->val) {
                    if (!first) {
                        first = prev;
                    }
                    second = node;
                }
                prev = node;
                node = node->right;
            }
        }
        int temp = first->val;
        first->val  = second->val;
        second->val = temp;
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
        node3.left = &node1; node3.right = &node2;
        s.recoverTree(&node3);
        print(&node3);
    }
    {
        TreeNode node0(0); TreeNode node1(1);
        node0.left = &node1;
        s.recoverTree(&node0);
        print(&node0);
    }
    return 0;
}
