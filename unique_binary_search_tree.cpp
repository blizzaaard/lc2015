// #96 Unique Binary Search Trees
//
// Given n, how many structurally unique BST's (binary search trees) that store
// values 1...n?
//
// For example,
//
// Given n = 3, there are a total of 5 unique BST's.
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


#include <iostream>
#include <vector>

class Solution {

  public:
    int numTrees(int n)
    {
        std::vector<int> count;
        count.push_back(1); // [0]
        count.push_back(1); // [1]
        for (int i = 2; i <= n; ++i) {
            int value = 0;
            for (int k = 0; k < i; ++k) {
                value += (count[k] * count[i - k - 1]);
            }
            count.push_back(value);
        }
        return count[n];
    }
};

int main()
{
    Solution s;
    std::cout << s.numTrees(1) << std::endl;
    std::cout << s.numTrees(2) << std::endl;
    std::cout << s.numTrees(3) << std::endl;
    std::cout << s.numTrees(4) << std::endl;
    std::cout << s.numTrees(5) << std::endl;
    return 0;
}
