// #136 Single Number
//
// Given an array of integers, every element appears twice except for one. Find
// that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement
// it without using extra memory?


#include <iostream>

class Solution {

  public:
    int singleNumber(int A[], int n)
    {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= A[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    {
        int A[] = { 1, 1, 2, 2, 3, 4, 4 };
        std::cout << s.singleNumber(A, sizeof A / sizeof *A) << std::endl;
    }
    return 0;
}
