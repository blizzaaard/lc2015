// #113 Path Sum II
//
// Given a binary tree and a sum, find all root-to-leaf paths where each path's
// sum equals the given sum.
//
// For example:
//
// Given the below binary tree and sum = 22,
//
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
//
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]


#include <iostream>
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

    void helper(std::vector<std::vector<int> > *result,
                std::vector<int>               *path,
                TreeNode                       *root,
                int                             sum)
    {
        if (!root) {
            return;
        }
        path->push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && 0 == sum) {
            result->push_back(*path);
        } else {
            helper(result, path, root->left,  sum);
            helper(result, path, root->right, sum);
        }
        path->pop_back();
    }

  public:
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum)
    {
        std::vector<std::vector<int> > result;
        std::vector<int>               path;
        helper(&result, &path, root, sum);
        return result;
    }
};

int main()
{
    Solution s;
    {
        TreeNode node1(1); TreeNode node2(2);
        node1.left = &node2;
        print(s.pathSum(&node1, 3));
    }
    {
        TreeNode node5(5);   TreeNode node4(4);   TreeNode node8(8);
        TreeNode node11(11); TreeNode node13(13); TreeNode node4a(4);
        TreeNode node7(7);   TreeNode node2(2);   TreeNode node1(1);
        node5.left = &node4;  node5.right = &node8;
        node4.left = &node11; node8.left  = &node13; node8.right = &node4;
        node11.left = &node7; node11.right = &node2; node4a.right = &node1;
        print(s.pathSum(&node5, 22));
    }
    return 0;
}
