// #55 Jump Game
//
// Given an array of non-negative integers, you are initially positioned at the
// first index of the array.
//
// Each element in the array represents your maximum jump length at that
// position.
//
// Determine if you are able to reach the last index.
//
// For example:
//
// A = [2,3,1,1,4], return true.
//
// A = [3,2,1,0,4], return false.


#include <iostream>

class Solution {

  public:
    bool canJump(int A[], int n)
    {
        if (n < 1) {
            return false;
        }

        // For each position, we calculate how many steps we can go.  If it's
        // zero, it means we cannot go further anymore.

        int maximum = 0;
        for (int i = 0; i < n - 1; ++i) {
            maximum = std::max(maximum - 1, A[i]);
            if (0 == maximum) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    {
        int A[] = { 0 };
        std::cout << s.canJump(A, sizeof A / sizeof *A) << std::endl;
    }
    {
        int A[] = { 1 };
        std::cout << s.canJump(A, sizeof A / sizeof *A) << std::endl;
    }
    {
        int A[] = { 0, 1 };
        std::cout << s.canJump(A, sizeof A / sizeof *A) << std::endl;
    }
    return 0;
}
