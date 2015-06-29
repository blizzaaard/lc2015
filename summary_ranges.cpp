// #228 Summary Ranges
//
// Given a sorted integer array without duplicates, return the summary of its
// ranges.
//
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].


#include <string>
#include <vector>
#include <

using namespace std;

class Solution {

    string toString(int start, int end)
    {
        ostringstream oss;
        oss << start;
        if (start != end) oss << "->" << end;
        return oss.str();
    }

  public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> result;
        if (nums.empty()) return result;
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1] + 1) {
                result.push_back(toString(start, nums[i - 1]));
                start = nums[i];
            }
        }
        result.push_back(toString(start, nums[nums.size() - 1]));
        return result;
    }
};
