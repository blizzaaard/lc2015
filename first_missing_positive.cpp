// #41 First Missing Positive
//
// Given an unsorted integer array, find the first missing positive integer.
//
// For example,
//
// Given [1,2,0] return 3,
//
// and [3,4,-1,1] return 2.
//
// Your algorithm should run in O(n) time and uses constant space.


#include <iostream>

class Solution {

  public:
    int firstMissingPositive(int A[], int n)
    {
        // Iterate over each element in the array and put the element into the
        // right position.
        //
        //    VALUE    1    2    3  ...     n      n + 1
        // POSITION  A[0] A[1] A[2] ... A[n - 1]   A[n]

        for (int i = 0; i < n; ) {
            if (1 <= A[i] && A[i] <= n && A[A[i] - 1] != A[i])
                std::swap(A[A[i] - 1], A[i]);
            else ++i;
        }

        // Then we iterate over the array again, and find the first position
        // where the value does not have the correct value (VALUE should be
        // POSITION + 1)

        for (int i = 0; i < n; ++i) {
            if (A[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};

int main()
{
    {
        int A[] = { 1, 2, 0 };
        Solution s;
        std::cout << s.firstMissingPositive(A, sizeof A / sizeof *A)
                  << std::endl;;
    }
    {
        int A[] = { 3, 4, -1, 1 };
        Solution s;
        std::cout << s.firstMissingPositive(A, sizeof A / sizeof *A)
                  << std::endl;
    }
    return 0;
}
