// #117 Populating Next Right Pointers in Each Noda II
//
// Follow up for problem "Populating Next Right Pointers in Each Node".
//
// What if the given tree could be any binary tree? Would your previous
// solution still work?
//
// Note:
//
// You may only use constant extra space.
//
// For example,
//
// Given the following binary tree,
//
//          1
//        /  \
//       2    3
//      / \    \
//     4   5    7
//
// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \    \
//     4-> 5 -> 7 -> NULL


#include <iostream>
#include <queue>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {

  public:
    void connect(TreeLinkNode *root)
    {
        std::queue<TreeLinkNode *> queue1;
        std::queue<TreeLinkNode *> queue2;
        if (root) {
            queue1.push(root);
        }
        while (!queue1.empty()) {
            TreeLinkNode *node = queue1.front();
            queue1.pop();
            if (node->left) {
                queue2.push(node->left);
            }
            if (node->right) {
                queue2.push(node->right);
            }
            if (!queue1.empty()) {
                node->next = queue1.front();
            }
            if (queue1.empty()) {
                queue1.swap(queue2);
            }
        }
    }
};
