// #42 Trapping Rain Water
//
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
//
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


#include <iostream>
#include <vector>

class Solution {

  public:
    int trap(int A[], int n)
    {
        int result = 0;

        // Calculate the heighest bar to the left of the current position.

        std::vector<int> left(n, 0);
        int maximum = 0;
        for (int i = 0; i < n; ++i) {
            left[i] = maximum;
            maximum = std::max(maximum, A[i]);
        }

        // Calculate the heighest bar to the right of the current position, and
        // calculate the water that can be trapped on each position.

        int right = 0;
        for (int i = n - 1; i >= 0; --i) {
            int local = std::min(left[i], right) - A[i];
            if (local > 0) {
                result += local;
            }
            right = std::max(right, A[i]);
        }

        return result;
    }
};

int main()
{
    int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    Solution s;
    std::cout << s.trap(A, sizeof A / sizeof *A) << std::endl;
    return 0;
}
