// #198 House Robber
//
// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping
// you from robbing each of them is that adjacent houses have security system
// connected and it will automatically contact the police if two adjacent
// houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of
// each house, determine the maximum amount of money you can rob tonight
// without alerting the police.

#include <iostream>
#include <vector>

using namespace std;

class Solution {

  public:
    int rob(vector<int> &num)
    {
        int n = num.size();

        if (0 == n) return 0;
        else if (1 == n) return num[0];
        else if (2 == n) return max(num[0], num[1]);

        vector<int> opt(n, 0);
        opt[0] = num[0];
        opt[1] = max(num[0], num[1]);
        for (int i = 2; i < num.size(); ++i) {
            opt[i] = max(num[i] + opt[i - 2], opt[i - 1]);
        }
        return opt[num.size() - 1];
    }
};

int main()
{
    Solution s;
    {
        vector<int> num;
        num.push_back(1);
        num.push_back(1);
        num.push_back(2);
        num.push_back(1);
        cout << s.rob(num) << endl;
    }
    return 0;
}
