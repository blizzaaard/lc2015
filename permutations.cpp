// #46 Permutations
//
// Given a collection of numbers, return all possible permutations.
//
// For example,
//
// [1,2,3] have the following permutations:
//
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].


#include <vector>
#include <iostream>

void print(const std::vector<std::vector<int> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
        std::cout << std::endl;
}

class Solution {

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void helper(std::vector<std::vector<int> > *res,
                std::vector<int>               *num,
                int                             index)
    {
        if (index == num->size() - 1) {
            res->push_back(*num);
            return;
        }
        for (int i = index; i < num->size(); ++i) {
            swap(&(*num)[index], &(*num)[i]);
            helper(res, num, index + 1);
            swap(&(*num)[index], &(*num)[i]);
        }
    }

  public:
    std::vector<std::vector<int> > permute(std::vector<int>& num)
    {
        std::vector<std::vector<int> > res;
        helper(&res, &num, 0);
        return res;
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(3);
        print(s.permute(num));
    }
    {
        std::vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(2);
        print(s.permute(num));
    }

    return 0;
}
