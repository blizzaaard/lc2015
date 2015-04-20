// #199 Binary Tree Right Side View 
//
// Given a binary tree, imagine yourself standing on the right side of it,
// return the values of the nodes you can see ordered from top to bottom.
//
// For example:
//
// Given the following binary tree,
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//
// You should return [1, 3, 4].


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;

class Solution {

  public:
    vector<int> rightSideView(TreeNode *node)
    {
        vector<int> result;
        if (!node) return result;
        queue<TreeNode *> queue;
        queue.push(node);
        int curr = 1;
        int next = 0;
        while (!queue.empty()) {
            node = queue.front();
            queue.pop();
            if (node->left) {
                queue.push(node->left);
                ++next;
            }
            if (node->right) {
                queue.push(node->right);
                ++next;
            }
            --curr;
            if (0 == curr) {
                result.push_back(node->val);
                swap(curr, next);
            }
        }
        return result;
    }
};
