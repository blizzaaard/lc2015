// #94 Binary Tree Inorder Traversal
//
// Given a binary tree, return the inorder traversal of its nodes' values.
//
// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [1,3,2].
//
// Note: Recursive solution is trivial, could you do it iteratively?
//
// confused what "{1,#,2,3}" means? > read more on how binary tree is
// serialized on OJ.
//
// OJ's Binary Tree Serialization:
//
// The serialization of a binary tree follows a level order traversal, where
// '#' signifies a path terminator where no node exists below.
//
// Here's an example:
//    1
//   / \
//  2   3
//     /
//    4
//     \
//      5
// The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".


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
            result->push_back(node->val);
            helper(result, node->right);
        }
    }

  public:
    std::vector<int> inorderTraversal(TreeNode *node)
    {
        std::vector<int> result;
        helper(&result, node);
        return result;
    }
};

class Solution {

  public:
    std::vector<int> inorderTraversal(TreeNode *node)
    {
        std::vector<int>       result;
        std::stack<TreeNode *> stack;
        while (node || !stack.empty()) {
            if (node) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                result.push_back(node->val);
                node = node->right;
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

    print(s.inorderTraversal(&node1));
    print(sr.inorderTraversal(&node1));

    return 0;
}
