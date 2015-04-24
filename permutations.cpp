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

using namespace std;

void print(const vector<vector<int> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[0].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {

    void helper(vector<vector<int> > *result, vector<int>& num, int index)
    {
        if (index >= num.size()) {
            result->push_back(num);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            swap(num[index], num[i]);
            helper(result, num, index + 1);
            swap(num[i], num[index]);
        }
    }

  public:
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int> > result;
        helper(&result, num, 0);
        return result;
    }
};

int main()
{
    Solution s;
    {
        vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(3);
        print(s.permute(num));
    }
    {
        vector<int> num;
        num.push_back(1);
        num.push_back(2);
        num.push_back(2);
        print(s.permute(num));
    }

    return 0;
}
