// #77 Combinations
//
// Given two integers n and k, return all possible combinations of k numbers
// out of 1 ... n.
//
// For example,
//
// If n = 4 and k = 2, a solution is:
//
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]


#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {

    void helper(std::vector<std::vector<int> > *result,
                std::vector<int>               *current,
                int                             index,
                int                             left,
                int                             n)
    {
        if (left == 0) {
            result->push_back(*current);
            return;
        }
        for (int i = index; i < n - left + 1; ++i) {
            current->push_back(i + 1);
            helper(result, current, i + 1, left - 1, n);
            current->pop_back();
        }
    }

  public:
    std::vector<std::vector<int> > combine(int n, int k)
    {
        std::vector<std::vector<int> > result;
        std::vector<int>               current;
        helper(&result, &current, 0, k, n);
        return result;
    }
};

int main()
{
    Solution s;
    print(s.combine(2, 1));
    print(s.combine(4, 2));
    return 0;
}
