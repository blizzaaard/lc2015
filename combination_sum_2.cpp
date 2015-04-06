// #40 Combination Sum II
//
// Given a collection of candidate numbers (C) and a target number (T), find
// all unique combinations in C where the candidate numbers sums to T.
//
// Each number in C may only be used once in the combination.
//
// Note:
//
//   - All numbers (including target) will be positive integers.
//
//   - Elements in a combination (a1, a2, … , ak) must be in non-descending
//     order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//
//   - The solution set must not contain duplicate combinations.
//
// For example, given candidate set 10,1,2,7,6,1,5 and target 8,
//
// A solution set is:
//
// [1, 7]
// [1, 2, 5]
// [2, 6]
// [1, 1, 6]


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
}

class Solution {

    void helper(std::vector<std::vector<int> > *results,
                std::vector<int>               *result,
                const std::vector<int>&         num,
                int                             index,
                int                             target)
    {
        if (0 > target) {
            return;
        }
        if (0 == target) {
            results->push_back(*result);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[i - 1] == num[i]) {
                continue;
            }
            result->push_back(num[i]);
            helper(results, result, num, i + 1, target - num[i]);
            result->pop_back();
        }
    }

  public:
    std::vector<std::vector<int> > combinationSum2(
            std::vector<int>& num,
            int               target)
    {
        std::vector<std::vector<int> > results;
        std::vector<int>               result;
        std::sort(num.begin(), num.end());
        helper(&results, &result, num, 0, target);
        return results;
    }
};

int main()
{
    std::vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);

    Solution s;
    print(s.combinationSum2(candidates, 8));
    return 0;
}
