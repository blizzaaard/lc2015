// #103 Binary Tree Zigzag Level Order Traversal
//
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
// For example:
//
// Given binary tree {3,9,20,#,#,15,7},
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// return its zigzag level order traversal as:
//
// [
//   [3],
//   [20,9],
//   [15,7]
// ]


#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(const std::vector<std::vector<int> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {

  public:
    std::vector<std::vector<int> > zigzagLevelOrder(TreeNode *node)
    {
        std::vector<std::vector<int> > result;
        if (!node) {
            return result;
        }
        result.resize(1);

        std::stack<TreeNode *> stack1;
        std::stack<TreeNode *> stack2;
        if (node) {
            stack1.push(node);
        }

        int  depth = 0;
        bool order = true;
        while (!stack1.empty()) {
            node = stack1.top();
            stack1.pop();
            result[depth].push_back(node->val);
            if (order) {
                if (node->left) {
                    stack2.push(node->left);
                }
                if (node->right) {
                    stack2.push(node->right);
                }
            } else {
                if (node->right) {
                    stack2.push(node->right);
                }
                if (node->left) {
                    stack2.push(node->left);
                }
            }
            if (stack1.empty()) {
                if (stack2.empty()) {
                    break;
                }
                order = !order;
                ++depth;
                result.resize(depth + 1);
                swap(stack1, stack2);
            }
        }
        return result;
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

        print(s.zigzagLevelOrder(&node1));
    }
    return 0;
}
