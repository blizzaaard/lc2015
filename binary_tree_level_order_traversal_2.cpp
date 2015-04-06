// #107 Binary Tree Level Order Traversal II
//
// Given a binary tree, return the bottom-up level order traversal of its
// nodes' values. (ie, from left to right, level by level from leaf to root).
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
// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


#include <iostream>
#include <queue>
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

class Solution_Recursion {

    void preorder(std::vector<std::vector<int> > *result,
                  TreeNode                       *node,
                  int                             level)
    {
        if (!node) {
            return;
        }
        if (level >= result->size()) {
            result->resize(level + 1);
        }
        (*result)[level].push_back(node->val);
        preorder(result, node->left, level + 1);
        preorder(result, node->right, level + 1);
    }

  public:
    std::vector<std::vector<int> > levelOrderBottom(TreeNode *root)
    {
        std::vector<std::vector<int> > result;
        preorder(&result, root, 0);
        std::reverse(result.begin(), result.end());
        return result;
    }
};

class Solution {

  public:
    std::vector<std::vector<int> > levelOrderBottom(TreeNode *node)
    {
        std::vector<std::vector<int> > result;
        if (!node) {
            return result;
        }

        std::queue<TreeNode *> queue;
        queue.push(node);
        result.resize(1);

        int numCurr = 1;
        int numNext = 0;
        int depth   = 0;
        while (!queue.empty()) {
            node = queue.front();
            queue.pop();
            result[depth].push_back(node->val);
            if (node->left) {
                queue.push(node->left);
                ++numNext;
            }
            if (node->right) {
                queue.push(node->right);
                ++numNext;
            }
            if (0 == --numCurr) {
                if (0 == numNext) {
                    break;
                }
                result.resize(++depth + 1);
                numCurr = numNext;
                numNext = 0;
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution_Recursion sr;
    Solution           s;
    {
        TreeNode node1(1);
        print(sr.levelOrderBottom(&node1));
        print(s.levelOrderBottom(&node1));
    }
    {
        TreeNode node1(3);  TreeNode node2(9); TreeNode node3(20);
        TreeNode node4(15); TreeNode node5(7);
        node1.left = &node2; node1.right = &node3;
        node3.left = &node4; node3.right = &node5;
        print(sr.levelOrderBottom(&node1));
        print(s.levelOrderBottom(&node1));
    }
    return 0;
}
