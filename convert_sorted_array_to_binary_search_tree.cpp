// #108 Convert Sorted Array to Binary Search Tree
//
// Given an array where elements are sorted in ascending order, convert it to a
// height balanced BST.


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

    TreeNode *helper(const std::vector<int>& num, int start, int end)
    {
        if (start > end) {
            return 0;
        }
        int mid = start + (end - start) / 2;

        TreeNode *node = new TreeNode(num[mid]);
        node->left  = helper(num, start, mid - 1);
        node->right = helper(num, mid + 1, end);

        return node;
    }

  public:
    TreeNode *sortedArrayToBST(const std::vector<int>& num)
    {
        return helper(num, 0, num.size() - 1);
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> num;
        num.push_back(0); num.push_back(1); num.push_back(2); num.push_back(3);
        num.push_back(4); num.push_back(5); num.push_back(6); num.push_back(7);
        print(s.sortedArrayToBST(num));
        std::cout << std::endl;
    }
    return 0;
}
