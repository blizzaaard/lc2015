// #137 Single Number II
//
// Given an array of integers, every element appears three times except for
// one. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement
// it without using extra memory?


#include <iostream>
#include <vector>

class Solution {

  public:
    int singleNumber(int A[], int n)
    {
        int result = 0;
        std::vector<int> count(32, 0);
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((A[j] >> i) & 1) {
                    count[i] = (count[i] + 1) % 3;
                }
            }
            result |= count[i] << i;
        }
        return result;
    }
};

int main()
{
    Solution s;
    {
        int A[] = { 1, 1, 1, 2, 2, 2, 3, 4, 4, 4 };
        std::cout << s.singleNumber(A, sizeof A / sizeof *A) << std::endl;
    }
    return 0;
}
