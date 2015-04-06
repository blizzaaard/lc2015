// #39 Combination Sum
//
// Given a set of candidate numbers (C) and a target number (T), find all
// unique combinations in C where the candidate numbers sums to T.
//
// The same repeated number may be chosen from C unlimited number of times.
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
// For example, given candidate set 2,3,6,7 and target 7,
//
// A solution set is:
//
// [7]
// [2, 2, 3]


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
                const std::vector<int>&         candidates,
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
        for (int i = index; i < candidates.size(); ++i) {
            result->push_back(candidates[i]);
            helper(results, result, candidates, i, target - candidates[i]);
            result->pop_back();
        }
    }

  public:
    std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates,
                                                  int               target)
    {
        std::vector<std::vector<int> > results;
        std::vector<int>               result;
        std::sort(candidates.begin(), candidates.end());
        helper(&results, &result, candidates, 0, target);
        return results;
    }
};

int main()
{
    std::vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);

    Solution s;
    print(s.combinationSum(candidates, 7));
    return 0;
}
