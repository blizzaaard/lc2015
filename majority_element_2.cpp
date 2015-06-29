// #229 Majority Element II
//
// Given an integer array of size n, find all elements that appear more than
// floor(n/3) times. The algorithm should run in linear time and in O(1) space.
//
// Hint:
//
// How many majority elements could it possibly have?


class Solution {

    bool check(vector<int>& nums, int value)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (value == nums[i]) ++count;
        }
        return count > n / 3;
    }
  public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int first  = 0, count1 = 0;
        int second = 0, count2 = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (0 != count1 && nums[i] == first) {
                ++count1;
            } else if (0 != count2 && nums[i] == second) {
                ++count2;
            } else if (count1 == 0) {
                first  = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                second = nums[i];
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        if (count1 > 0 && check(nums,  first)) result.push_back(first);
        if (count2 > 0 && check(nums, second)) result.push_back(second);
        return result;
    }
};
