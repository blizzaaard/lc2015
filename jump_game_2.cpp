// #45 Jump Game II
//
// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// For example:
//
// Given array A = [2,3,1,1,4]
//
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from
// index 0 to 1, then 3 steps to the last index.)


#include <iostream>

class Solution {

  public:
    int jump(int A[], int n)
    {
        int jumps   = 0;
        int lastMax = 0;
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
            if (i > lastMax) {
                ++jumps;
                lastMax = currMax;
            }
            currMax = std::max(currMax, i + A[i]);
        }
        return jumps;
    }
};

int main()
{
    int A[] = { 2, 3, 1, 1, 4 };
    Solution s;
    std::cout << s.jump(A, sizeof A / sizeof *A) << std::endl;
    return 0;
}
