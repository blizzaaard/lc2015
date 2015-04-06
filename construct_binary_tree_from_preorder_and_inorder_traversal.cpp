// #105 Construct Binary Tree from Preorder and Inorder Traversal
//
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
//
// You may assume that duplicates do not exist in the tree.


#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *node)
{
    if (node) {
        print(node->left);
        std::cout << node->val << " ";
        print(node->right);
    }
}

class Solution {

    int getIndex(const std::vector<int>& inorder, int value)
        // Return the index of the specified 'value' in the specified
        // 'inorder'.
    {
        for (int i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == value) {
                return i;
            }
        }
        return -1;
    }

    TreeNode *helper(const std::vector<int>&  preorder,
                     const std::vector<int>&  inorder,
                     int                      start,
                     int                      end,
                     int                     *index)
    {
        if (start > end) {
            return 0;
        }

        int value = preorder[(*index)++];
        TreeNode *node = new TreeNode(value);

        int mid = getIndex(inorder, value);

        node->left  = helper(preorder, inorder, start, mid - 1, index);
        node->right = helper(preorder, inorder, mid + 1, end, index);

        return node;
    }

  public:
    TreeNode *buildTree(const std::vector<int>& preorder,
                        const std::vector<int>& inorder)
    {
        int index = 0;
        return helper(preorder, inorder, 0, preorder.size() - 1, &index);
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> preorder;
        preorder.push_back(1); preorder.push_back(2); preorder.push_back(4);
        preorder.push_back(5); preorder.push_back(3); preorder.push_back(6);
        preorder.push_back(7);

        std::vector<int> inorder;
        inorder.push_back(4); inorder.push_back(5); inorder.push_back(2);
        inorder.push_back(1); inorder.push_back(6); inorder.push_back(3);
        inorder.push_back(7);

        print(s.buildTree(preorder, inorder));
        std::cout << std::endl;
    }
    return 0;
}
