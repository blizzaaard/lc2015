// #33 Search in Rotated Sorted Array
//
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
//
// You may assume no duplicate exists in the array.


// 1. A[start] <= A[mid]
//
//         A[mid]
//           |
//           |/
//           /
//          /|
// A[start]  |   / A[end - 1]
//           |  /
//           | /
//           |
//
// if A[start] <= target < A[mid], the target must be in the left part,
// otherwise, the target must be in the right part.
//
// 2. A[start] > A[mid]
//
//           A[mid]
//              |
//            / |
//           /  |
//          /   |
// A[start]     |/ A[end - 1]
//              /
//             /|
//              |
//
// if A[mid] < target <= A[end], the target must be in the right part,
// otherwise, the target must be in the left part.

#include <iostream>

class Solution {
  public:
    int search(int A[], int n, int target)
    {
        int start = 0;
        int end   = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                return mid;
            } else if (A[start] <= A[mid]) {
                if (A[start] <= target && target < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target <= A[end] && target > A[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    int A[] = { 3, 4, 5, 6, 1, 2 };
    Solution s;
    std::cout << s.search(A, sizeof(A) / sizeof(A[0]), 1) << std::endl;
    return 0;
}
