// #90 Subsets II
//
// Given a collection of integers that might contain duplicates, S, return all
// possible subsets.
//
// Note:
//
//  - Elements in a subset must be in non-descending order.
//
//  - The solution set must not contain duplicate subsets.
//
// For example,
// If S = [1,2,2], a solution is:
//
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
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


// { 1, 1, 1 }
//
// A: 1      // This is the 1st 1.
//
//
// B:   1    // This is the 2nd 1.
//
//
// C:     1  // This is the 3rd 1 and it should be included even if it's the
//           // same as S[i-1] because S[i-1] is not visited in the same level.
//
// D:   1    // This is the 3rd 1 and it should be skipped since it's the same
//           // as the previous value visited at step 'B' in the same level.
//
// E: 1      // This is the 2nd 1 and it should be skipped since it's the same
//           // as the previous value visited at step 'A' in the same level.
//
// F: 1      // This is the 3rd 1 and it should be skipped since it's the same
//           // as the previous value visited at step 'E' in the same level.
//
// Therefore, only step 'A', 'B' and 'C' dump the subsets which are { 1 },
// { 1, 1 } and { 1, 1, 1 }, respectively.

class Solution_Recursion {

    void helper(std::vector<std::vector<int> > *subsets,
                std::vector<int>               *subset,
                const std::vector<int>&         S,
                int                             index)
    {
        if (index == S.size()) {
            return;
        }
        int last = index;
        for (int i = index; i < S.size(); ++i) {
            // We cannot just test S[i] == S[i - 1] here because when we are
            // generating the last 1 in { 1, 1, 1 }, we should not exclude the
            // last 1.
            //
            // The idea is that at the same level, if S[i] is the same as the
            // previous element, we should just skip the duplicate S[i].
            // However, if we are accessing the duplicate S[i] in the next
            // level, we do need to include the duplicate.  That's why we use
            // the local 'last' variable to record the last element instead of
            // S[i - 1] because each level (or function call) has its own copy
            // of the 'last' variable.

            if (index != i && S[i] == S[last]) {
                continue;
            }
            last = i;
            subset->push_back(S[i]);
            subsets->push_back(*subset);
            helper(subsets, subset, S, i + 1);
            subset->pop_back();
        }
    }

  public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &S)
    {
        std::vector<std::vector<int> > subsets(1);
        std::vector<int>               subset;
        std::sort(S.begin(), S.end());
        helper(&subsets, &subset, S, 0);
        return subsets;
    }
};


// { 1, 2, 2 }
//
//  STEPS   SUBSETS
// =======  =======
//
// <start>  <empty>
//          -------
// apply 1   1       currSize = 1; lastSize = 1; start = 0 since S[i-1] != S[i]
//          -------
// apply 2   2       currSize = 2; lastSize = 1; start = 0 since S[i-1] != S[i]
// apply 2   1 2
//          -------
// apply 2   2 2     currSize = 4; lastSize = 2; start = 2 since S[i-1] == S[i]
// apply 2   1 2 2

class Solution {

  public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &S)
    {
        std::vector<std::vector<int> > subsets(1);
        sort(S.begin(), S.end());
        int lastSize = 0;
        for(int i = 0; i < S.size(); ++i) {
            // If S[i] is the same as S[i - 1], we do not apply S[i] to the
            // results that has already been applied by S[i - 1].
            int start = (0 == i || S[i - 1] != S[i]) ? 0 : lastSize;

            int currSize = subsets.size();
            for(int j = start; j < currSize; j++) {
                subsets.push_back(subsets[j]);
                subsets.back().push_back(S[i]);
            }
            lastSize = currSize;
        }
        return subsets;
    }
};

using namespace std;

class Solution1 {

    void helper(vector<vector<int> >& result, vector<int>& path, const vector<int>& set, int index)
    {
        for (int i = index; i < set.size(); ++i) {
            bool skip = false;
            if (i != index) {
                for (int j = index; j < i; ++j) {
                    if (set[j] == set[i]) {
                        skip = true;
                        break;
                    }
                }
            }
            if (!skip) {
                path.push_back(set[i]);
                result.push_back(path);
                helper(result, path, set, i + 1);
                path.pop_back();
            }
        }
    }

  public:
    vector<vector<int> > subsetsWithDup(vector<int> &set)
    {
        vector<vector<int> > result(1);
        vector<int>          path;
        sort(set.begin(), set.end());
        helper(result, path, set, 0);
        return result;
    }
};

int main()
{
    {
        std::vector<int> S;
        S.push_back(1);
        S.push_back(1);
        S.push_back(1);

        Solution_Recursion sr;
        print(sr.subsetsWithDup(S));
    }

    {
        std::vector<int> S;
        S.push_back(1);
        S.push_back(2);
        S.push_back(2);

        Solution s;
        print(s.subsetsWithDup(S));

        Solution_Recursion sr;
        print(sr.subsetsWithDup(S));
    }
    return 0;
}
