// #47 Permutations II
//
// Given a collection of numbers that might contain duplicates, return all
// possible unique permutations.
//
// For example,
//
// [1,1,2] have the following unique permutations:
//
// [1,1,2], [1,2,1], and [2,1,1].


#include <vector>
#include <iostream>

void print(const std::vector<std::vector<int> >& res)
{
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    bool skip(int index, int i, const std::vector<int>& num)
        // Return 'true' if at least one charactor in 'num[index, i)' is the
        // same as 'num[i]', and 'false' otherwise.
    {
        for (int j = index; j < i; ++j) {
            if (num[j] == num[i]) {
                return true;
            }
        }
        return false;
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
            if (i != index && skip(index, i, *num)) {
                // We need to compare 'num[i]' to every charactor in
                // 'num[index, i)', rather than only 'num[i - 1]'.
                //
                // e.g. for 0 1 0 (this sequence will appear after several
                // swaps even if it's sorted on initialization), we shouldn't
                // only check the 3rd '0' with the 2nd '1' and then swap the
                // 1st '0' with the 3rd '0'.

                continue;
            }
            swap(&(*num)[index], &(*num)[i]);
            helper(res, num, index + 1);
            swap(&(*num)[index], &(*num)[i]);
        }
    }

 public:
    std::vector<std::vector<int> > permuteUnique(std::vector<int>& num)
    {
        std::vector<std::vector<int> > res;
        helper(&res, &num, 0);
        return res;
    }
};

using namespace std;

class Solution1 {

    void helper(vector<vector<int> > *result, vector<int>& num, int index)
    {
        if (index >= num.size()) {
            result->push_back(num);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            bool skip = false;
            if (i != index) {
                for (int j = index; j < i; ++j) {
                    if (num[j] == num[i]) {
                        skip = true;
                        break;
                    }
                }
            }
            if (!skip) {
                swap(num[index], num[i]);
                helper(result, num, index + 1);
                swap(num[i], num[index]);
            }
        }
    }

  public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        helper(&result, num, 0);
        return result;
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> num;
        num.push_back(-1);
        num.push_back(-1);
        num.push_back(3);
        num.push_back(-1);
        print(s.permuteUnique(num));
    }
    {
        std::vector<int> num;
        num.push_back(0);
        num.push_back(1);
        num.push_back(0);
        num.push_back(0);
        num.push_back(9);
        print(s.permuteUnique(num));
    }
    {
        std::vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(2);
        num.push_back(2);
        print(s.permuteUnique(num));
    }

    return 0;
}
