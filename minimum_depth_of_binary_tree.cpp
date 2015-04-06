// #111 Minimum Depth of Binary Tree
//
// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.


#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution_DFS {

  public:
    int minDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        int left  = minDepth(root->left);
        int right = minDepth(root->right);
        if (!root->left) {
            return right + 1;
        } else if (!root->right) {
            return left + 1;
        } else {
            return (left < right ? left : right) + 1;
        }
    }
};

class Solution {

  public:
    int minDepth(TreeNode *root)
    {
        int currNodes = 1;
        int nextNodes = 0;
        int depth     = 0;
        std::queue<TreeNode *> queue;
        if (root) {
            queue.push(root);
        }
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();
            --currNodes;
            if (!node->left && !node->right) {
                return depth + 1;
            }
            if (node->left) {
                queue.push(node->left);
                ++nextNodes;
            }
            if (node->right) {
                queue.push(node->right);
                ++nextNodes;
            }
            if (0 == currNodes) {
                // All the nodes in the current level have been visited.  Now,
                // increment the depth and continue to visit the nodes in the
                // next level.

                ++depth;
                currNodes = nextNodes;
                nextNodes = 0;
            }
        }
        return depth;
    }
};

int main()
{
    Solution_DFS sd;
    Solution     s;
    {
        TreeNode *node1 = new TreeNode(1);
        TreeNode *node2 = new TreeNode(2);
        node1->left = node2;

        std::cout << sd.minDepth(node1) << std::endl;
        std::cout << s.minDepth(node1) << std::endl;
    }
    return 0;
}
