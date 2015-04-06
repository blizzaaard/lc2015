#include <algorithm>
#include <iostream>

class Solution {
public:
    double helper(int A[], int l, int B[], int m, int left, int right)
    {
        if (left > right) {
            return helper(B, m, A, l,
                          std::max(0, (l + m) / 2 - l),
                          std::min(m - 1, (l + m) / 2));
        }
        int i = (left + right) / 2;
        int j = (l + m) / 2 - i - 1;
        if (j < m - 1 && A[i] > B[j + 1]) {
            // median was too large
            return helper(A, l, B, m, left, i - 1);
        } else if (j >= 0 && A[i] < B[j]) {
            // median was too small
            return helper(A, l, B, m, i + 1, right);
        } else {
            if (1 == (l + m) % 2) {
                return A[i];
            } else if (i > 0) {
                return (A[i] + std::max(B[j], A[i - 1])) / 2.0;
            } else {
                return (A[i] + B[j]) / 2.0;
            }
        }
    }
    double findMedianSortedArrays(int A[], int l, int B[], int m) {
        return helper(A, l, B, m,
                      std::max(0, (l + m) / 2 - m),
                      std::min(l - 1, (l + m) / 2));
    }
};

int main()
{
    int A[] = { 0 };
    int B[] = { 1 };
    Solution s;
    std::cout << s.findMedianSortedArrays(A, 0, B, 1) << std::endl;
    return 0;
}