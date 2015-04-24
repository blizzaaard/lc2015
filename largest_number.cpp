// #179 Largest Number
//
// Given a list of non negative integers, arrange them such that they form the
// largest number.
//
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
// Note: The result may be very large, so you need to return a string instead
// of an integer.


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string toString(int n)
{
    ostringstream oss;
    oss << n;
    return oss.str();
}

struct Comp {

    bool operator()(int a, int b) const
    {
        string sa = toString(a);
        string sb = toString(b);
        if (sa + sb > sb + sa) return true;
        else return false;
    }
};

class Solution {

  public:
    string largestNumber(vector<int>& nums)
    {
        string result;
        sort(nums.begin(), nums.end(), Comp());
        for (int i = 0; i < nums.size(); ++i) {
            if (result.empty() && 0 == nums[i]) continue;
            result += toString(nums[i]);
        }
        return result.empty() ? "0" : result;
    }
};

int main()
{
    Solution s;
    {
        vector<int> nums;
        nums.push_back(3);
        nums.push_back(30);
        nums.push_back(34);
        nums.push_back(5);
        nums.push_back(9);
        cout << s.largestNumber(nums) << endl;
    }
    {
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(0);
        cout << s.largestNumber(nums) << endl;
    }
    return 0;
}

