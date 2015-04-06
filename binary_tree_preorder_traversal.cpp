// #144 Binary Tree Preorder Traversal
//
// Given a binary tree, return the preorder traversal of its nodes' values.
//
// For example:
//
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,2,3].
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

    void helper(std::vector<int> *result, TreeNode *node)
    {
        if (node) {
            result->push_back(node->val);
            helper(result, node->left);
            helper(result, node->right);
        }
    }

  public:
    std::vector<int> preorder(TreeNode *node)
    {
        std::vector<int> result;
        helper(&result, node);
        return result;
    }
};

class Solution {

  public:
    std::vector<int> preorder(TreeNode *node)
    {
        std::vector<int>       result;
        std::stack<TreeNode *> stack;
        while (node || !stack.empty()) {
            if (node) {
                result.push_back(node->val);
                if (node->right) {
                    stack.push(node->right);
                }
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
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

    print(s.preorder(&node1));
    print(sr.preorder(&node1));

    return 0;
}
