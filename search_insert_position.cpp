// #35 Search Insert Position
//
// Given a sorted array and a target value, return the index if the target is
// found. If not, return the index where it would be if it were inserted in
// order.
//
// You may assume no duplicates in the array.
//
// Here are few examples.
//
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0


#include <iostream>

class Solution {

  public:
    int searchInsert(int A[], int n, int target)
    {
        int i = 0;
        for (i = 0; i < n; ++i) {
            if (target <= A[i]) {
                return i;
            }
        }
        return i;
    }
};

int main()
{
    int A[] = { 1, 3, 5, 6 };
    const int length = sizeof A / sizeof *A;
    Solution s;
    std::cout << s.searchInsert(A, length, 5) << std::endl;
    std::cout << s.searchInsert(A, length, 2) << std::endl;
    std::cout << s.searchInsert(A, length, 7) << std::endl;
    std::cout << s.searchInsert(A, length, 0) << std::endl;
    return 0;
}
