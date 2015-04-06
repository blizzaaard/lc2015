// #78 Subsets
//
// Given a set of distinct integers, S, return all possible subsets.
//
// Note:
//  - Elements in a subset must be in non-descending order.
//  - The solution set must not contain duplicate subsets.
//
// For example,
// If S = [1,2,3], a solution is:
//
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


#include <vector>
#include <iostream>

void print(const std::vector<std::vector<int> >& subsets)
{
    for (int i = 0; i < subsets.size(); ++i) {
        for (int j = 0; j < subsets[i].size(); ++j) {
            std::cout << subsets[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


// { 1, 2, 3 }
//
// A: 1      // { 1 }
// B:   2    // { 1, 2 }
// C:     3  // { 1, 2, 3 }
// D:   3    // { 1, 3 }
// E: 2      // { 2 }
// F:   3    // { 2, 3 }
// G: 3      // { 3 }
//
// The empty subset should be added at the beginning.

class Solution_Recursion {

    void helper(std::vector<std::vector<int> > *subsets,
                std::vector<int>               *subset,
                const std::vector<int>&         S,
                int                             index)
    {
        if (index == S.size()) {
            return;
        }
        for (int i = index; i < S.size(); ++i) {
            subset->push_back(S[i]);
            subsets->push_back(*subset);
            helper(subsets, subset, S, i + 1);
            subset->pop_back();
        }
    }

  public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S)
    {
        std::vector<std::vector<int> > subsets(1);
        std::vector<int>               subset;
        std::sort(S.begin(), S.end());
        helper(&subsets, &subset, S, 0);
        return subsets;
    }
};

// { 1, 2, 3 }
//
//  STEPS   SUBSETS
// =======  =======
//
// <start>  <empty>
//          -------
// apply 1   1       currSize = 1
//          -------
// apply 2   2       currSize = 2
// apply 2   1 2
//          -------
// apply 3   3       currSize = 4
// apply 3   1 3
// apply 3   2 3
// apply 3   1 2 3

class Solution {

  public:
    std::vector<std::vector<int> > subsets(std::vector<int> &S)
    {
        std::vector<std::vector<int> > subsets(1);
        sort(S.begin(), S.end());
        for(int i = 0; i < S.size(); ++i) {
            int currSize = subsets.size();
            for(int j = 0; j < currSize; j++) {
                subsets.push_back(subsets[j]);
                subsets.back().push_back(S[i]);
            }
        }
        return subsets;
    }
};

int main()
{
    std::vector<int> S;
    S.push_back(1);
    S.push_back(2);
    S.push_back(3);

    Solution_Recursion sr;
    print(sr.subsets(S));

    Solution s;
    print(s.subsets(S));

    return 0;
}
