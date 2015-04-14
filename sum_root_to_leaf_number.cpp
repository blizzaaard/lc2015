// #129 Sum Root to Leaf Numbers
//
// Given a binary tree containing digits from 0-9 only, each root-to-leaf path
// could represent a number.
//
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// For example,
//
//     1
//    / \
//   2   3
//
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
//
// Return the sum = 12 + 13 = 25.


#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

    int toInt(const std::vector<int>& digits)
    {
        int result = 0;
        for (int i = 0; i < digits.size(); ++i) {
            result = result * 10 + digits[i];
        }
        return result;
    }

    void helper(int *result, std::vector<int> *digits, TreeNode *root)
    {
        if (!root) {
            return;
        }
        digits->push_back(root->val);
        if (!root->left && !root->right) {
            *result += toInt(*digits);
        } else {
            helper(result, digits, root->left);
            helper(result, digits, root->right);
        }
        digits->pop_back();
    }

  public:
    int sumNumbers(TreeNode *root)
    {
        int result = 0;

        if (!root) {
            return result;
        }
        std::vector<int> digits;
        helper(&result, &digits, root);
        return result;
    }
};

class Solution1 {

    void helper(TreeNode *node, int *result, int sum)
    {
        if (!node) return;
        sum += node->val;
        if (!node->left && !node->right) {
            *result += sum;
        } else {
            helper(node->left,  result, sum * 10);
            helper(node->right, result, sum * 10);
        }
    }

  public:
    int sumNumbers(TreeNode *root)
    {
        int result = 0;
        helper(root, &result, 0);
        return result;
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(1); TreeNode node2(2); TreeNode node3(3);
        node1.left = &node2; node1.right = &node3;
        std::cout << s.sumNumbers(&node1) << std::endl;
    }
    return 0;
}
