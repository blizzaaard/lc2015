// #53 Maximum Subarray
//
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest sum.
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//
// click to show more practice.
//
// More practice:
//
// If you have figured out the O(n) solution, try coding another solution using
// the divide and conquer approach, which is more subtle.


#include <algorithm>
#include <iostream>

class Solution {
public:
    int maxSubArray(int A[], int n)
    {
        if (n < 1) {
            return 0;
        }

        int localMax  = A[0];
            // This variable maintains the local maximum ending at A[i].

        int globalMax = A[0];
            // This variable maintains the global maximum ending at A[i].

        for (int i = 1; i < n; ++i) {
            localMax  = std::max(
                    A[i],             // start a new sequence from A[i]
                    localMax + A[i]); // include A[i] in the existing sequence

            globalMax = std::max(localMax, globalMax);
        }
        return globalMax;
    }
};

int main()
{
    Solution s;
    {
        int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        std::cout << s.maxSubArray(A, sizeof(A) / sizeof(A[0])) << std::endl;
    }
    {
        int A[] = { -3, -1, -2 };
        std::cout << s.maxSubArray(A, sizeof(A) / sizeof(A[0])) << std::endl;
    }
    return 0;
}
