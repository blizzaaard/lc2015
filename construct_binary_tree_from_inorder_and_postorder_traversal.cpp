// #106 Construct Binary Tree from Inorder and Postorder Traversal
//
// Given inorder and postorder traversal of a tree, construct the binary tree.
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

    TreeNode *helper(const std::vector<int>&  inorder,
                     const std::vector<int>&  postorder,
                     int                      start,
                     int                      end,
                     int                     *index)
    {
        if (start > end) {
            return 0;
        }
        int value = postorder[(*index)--];
        TreeNode *node = new TreeNode(value);

        int mid = getIndex(inorder, value);

        node->right = helper(inorder, postorder, mid + 1, end, index);
        node->left  = helper(inorder, postorder, start, mid - 1, index);

        return node;
    }

  public:
    TreeNode *buildTree(const std::vector<int>& inorder,
                        const std::vector<int>& postorder)
    {
        int index = inorder.size() - 1;
        return helper(inorder, postorder, 0, inorder.size() - 1, &index);
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> inorder;
        inorder.push_back(4); inorder.push_back(5); inorder.push_back(2);
        inorder.push_back(1); inorder.push_back(6); inorder.push_back(3);
        inorder.push_back(7);

        std::vector<int> postorder;
        postorder.push_back(4); postorder.push_back(5); postorder.push_back(2);
        postorder.push_back(6); postorder.push_back(7); postorder.push_back(3);
        postorder.push_back(1);

        print(s.buildTree(inorder, postorder));
        std::cout << std::endl;
    }
    return 0;
}
