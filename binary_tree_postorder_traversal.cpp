// #145 Binary Tree Postorder Traversal
//
// Given a binary tree, return the postorder traversal of its nodes' values.
//
// For example:
//
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].
//
// Note: Recursive solution is trivial, could you do it iteratively?


#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution_Recursion {

    void helper(std::vector<int> *result, TreeNode* node)
    {
        if (node) {
            helper(result, node->left);
            helper(result, node->right);
            result->push_back(node->val);
        }
    }

  public:
    std::vector<int> postorderTraversal(TreeNode *node)
    {
        std::vector<int> result;
        helper(&result, node);
        return result;
    }
};

class Solution {

  public:
    std::vector<int> postorderTraversal(TreeNode *node)
    {
        std::vector<int>        result;
        std::stack<TreeNode *>  stack;
        TreeNode               *last = 0;
        while (node || !stack.empty()) {
            if (node) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                if (!node->right || node->right == last) {
                    // When there's no right child or the last visited node is
                    // the right child.

                    stack.pop();
                    result.push_back(node->val);
                    last = node;
                    node = 0;
                } else {
                    // The last visited node is the left child and the right
                    // child is not null and has not been visited.

                    node = node->right;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution           s;
    Solution_Recursion sr;

    //    1
    //   / \
    //  2   3
    //     /
    //    4
    //     \
    //      5
    TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
    TreeNode node4(4); TreeNode node5(5);

    node1.left = &node2; node1.right = &node3;
    node3.left = &node4; node4.right = &node5;

    print(s.postorderTraversal(&node1));
    print(sr.postorderTraversal(&node1));

    return 0;
}
