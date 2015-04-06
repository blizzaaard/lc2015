// #95 Unique Binary Search Trees II
//
// Given n, generate all structurally unique BST's (binary search trees) that
// store values 1...n.
//
// For example,
//
// Given n = 3, your program should return all 5 unique BST's shown below.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


#include <iostream>
#include <stack>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *node)
{
    std::stack<TreeNode *> stack;
    while (node || !stack.empty()) {
        if (node) {
            stack.push(node);
            node = node->left;
        } else {
            node = stack.top();
            stack.pop();
            std::cout << node->val << " ";
            node = node->right;
        }
    }
    std::cout << std::endl;
}

void print(const std::vector<TreeNode *>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        print(result[i]);
    }
}

class Solution {

    std::vector<TreeNode *> helper(int min, int max)
        // Return a list of valid BSTs that can be constructed using the
        // numbers in [min, max].
    {
        std::vector<TreeNode *> result;

        if (min > max) {
            result.push_back(0); // root == null
        } else if (min == max) {
            result.push_back(new TreeNode(min));
        } else {
            for (int i = min; i <= max; ++i) {
                std::vector<TreeNode *> left  = helper(min, i - 1);
                std::vector<TreeNode *> right = helper(i + 1, max);

                for (std::vector<TreeNode *>::const_iterator
                        it  = left.begin();
                        it != left.end();
                      ++it)
                {
                    for (std::vector<TreeNode *>::const_iterator
                             jt  = right.begin();
                             jt != right.end();
                           ++jt)
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left  = *it;
                        node->right = *jt;
                        result.push_back(node);
                    }
                }
            }
        }
        return result;
    }

  public:
    std::vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
};

int main()
{
    Solution s;
    print(s.generateTrees(1));
    print(s.generateTrees(2));
    print(s.generateTrees(3));
    print(s.generateTrees(4));
    print(s.generateTrees(5));
    return 0;
}
