// #114 Flatten Binary Tree to Linked List
//
// Given a binary tree, flatten it to a linked list in-place.
//
// For example,
//
// Given
//
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
//
// The flattened tree should look like:
//
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
//
// Hints:
//
// If you notice carefully in the flattened tree, each node's right child
// points to the next node of a pre-order traversal.


#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *node)
{
    while (node) {
        std::cout << node->val << " ";
        node = node->right;
    }
    std::cout << std::endl;
}

class SolutionRecursion {

    void helper(TreeNode *node, TreeNode*& prev)
    {
        if (!node) return;
        TreeNode *left = node->left, *right = node->right;
        if (prev) prev->right = node;
        prev = node;
        helper(left, prev);
        helper(right, prev);
    }

  public:
    void flatten(TreeNode *root)
    {
        TreeNode *prev = 0;
        helper(root, prev);
    }
};

class Solution {

  public:
    void flatten(TreeNode *node)
    {
        TreeNode *last = 0;

        std::stack<TreeNode *> stack;
        while (node || !stack.empty()) {
            if (node) {
                if (last) {
                    last->right = node;
                }
                if (node->right) {
                    stack.push(node->right);
                }
                last = node;
                node = node->left;
                last->left = 0;
            } else {
                node = stack.top();
                stack.pop();
            }
        }
    }
};

int main()
{
    SolutionRecursion sr;
    Solution          s;
    {
        TreeNode node1(1); TreeNode node2(2);
        node1.left = &node2;
        sr.flatten(&node1);
        print(&node1);
    }
    {
        TreeNode node1(1); TreeNode node2(2);
        node1.right = &node2;
        sr.flatten(&node1);
        print(&node1);
    }
    {
        TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
        TreeNode node4(4); TreeNode node5(5); TreeNode node6(6);
        node1.left = &node2; node1.right = &node5;
        node2.left = &node3; node2.right = &node4;
        node5.right = &node6;
        sr.flatten(&node1);
        print(&node1);
    }
    {
        TreeNode node1(1); TreeNode node2(2);
        node1.right = &node2;
        s.flatten(&node1);
        print(&node1);
    }
    {
        TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
        TreeNode node4(4); TreeNode node5(5); TreeNode node6(6);
        node1.left = &node2; node1.right = &node5;
        node2.left = &node3; node2.right = &node4;
        node5.right = &node6;
        s.flatten(&node1);
        print(&node1);
    }
    return 0;
}
