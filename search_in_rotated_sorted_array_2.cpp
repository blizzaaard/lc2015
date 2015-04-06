// #81 Search in Rotated Sorted Array II
//
// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
// Write a function to determine if a given target is in the array.


// Unlike in "Search in Rotated Sorted Array", we cannot compare A[start] and
// A[mid] to determine which cases it is.
//
//   1. A[start] <= A[mid]
//
//           A[mid]
//             |
//             |/
//             /
//            /|
//   A[start]  |   / A[end - 1]
//             |  /
//             | /
//             |
//
//   if A[start] <= target < A[mid], the target must be in the left part,
//   otherwise, the target must be in the right part.
//
//   2. A[start] > A[mid]
//
//             A[mid]
//                |
//              / |
//             /  |
//            /   |
//   A[start]     |/ A[end - 1]
//                /
//               /|
//                |
//
//   if A[mid] < target <= A[end], the target must be in the right part,
//   otherwise, the target must be in the left part.
//
// The above is not true anymore when we have duplicates. For example, when
// A[start] == A[mid], there's no way to differentiate the following two cases,
// so we don't know which part the target is in.
//
// 1. the target is in the left part.
//
//                   A[mid]
//                      |
//                /     |
//               /      |
//         _____/     __|__
// A[start]          /  |  A[end - 1]
//                  /   |
//                 /    |
//                      |
//
// 2. the target is in the right part.
//
//        A[mid]
//           |
//           |    /
//           |   /
//         __|__/     _____
// A[start]  |       /     A[end - 1]
//           |      /
//           |     /
//           |


#include <iostream>

class Solution {
  public:
    bool search(int A[], int n, int target)
    {
        int start = 0;
        int end   = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target == A[mid]) {
                return true;
            } else if (A[start] < A[mid]) {
                if (A[start] <= target && target < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (A[start] > A[mid]) {
                if (target <= A[end] && target > A[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                // when A[start] == A[mid], we don't know which part should be
                // dropped, so the only thing we can do is to increment the
                // starting position and try it again, but the time complexity
                // is not O(lgn) anymore (it's O(n)).
                ++start;
            }
        }
        return false;
    }
};

int main()
{
    int A[] = { 2, 3, 4, 5, 6, 1, 2 };
    Solution s;
    std::cout << s.search(A, sizeof(A) / sizeof(A[0]), 1) << std::endl;
    std::cout << s.search(A, sizeof(A) / sizeof(A[0]), 8) << std::endl;
    return 0;
}
