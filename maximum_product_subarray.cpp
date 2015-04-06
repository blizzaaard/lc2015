// #152 Maximum Product Subarray
//
// Find the contiguous subarray within an array (containing at least one
// number) which has the largest product.
//
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.


#include <algorithm>
#include <iostream>

class Solution {
  public:
    int maxProduct(int A[], int n)
    {
        if (n < 0) {
            return 0;
        }

        int localMax = A[0];
            // This variable maintains the local maximum ending at A[i].

        int localMin = A[0];
            // This variable maintains the local minimum ending at A[i].  This
            // is needed because (neg * neg = pos);

        int globalMax = A[0];
            // This variable maintains the global maximum ending at A[i].

        for (int i = 1; i < n; ++i) {
            int tmpLocalMax =
                std::max(A[i], // start a new sequence from A[i]
                         std::max(localMax * A[i],   // include A[i] in the
                                                     // existing sequence, A[i]
                                                     // is positive
                                  localMin * A[i])); // include A[i] in the
                                                     // existing sequence, A[i]
                                                     // is negative
            int tmpLocalMin =
                std::min(A[i], // start a new sequence from A[i]
                         std::min(localMax * A[i],   // include A[i] in the
                                                     // existing sequence, A[i]
                                                     // is negative
                                  localMin * A[i])); // include A[i] in the
                                                     // existing sequence, A[i]
                                                     // is positive
                // This variable is needed because (neg * neg = pos);

            localMax = tmpLocalMax;
            localMin = tmpLocalMin;

            globalMax = std::max(globalMax, localMax);
        }
        return globalMax;
    }
};

int main()
{
    int A[] = { 2, 3, -2, 4 };
    Solution s;
    std::cout << s.maxProduct(A, sizeof(A) / sizeof(A[0])) << std::endl;
    return 0;
}
