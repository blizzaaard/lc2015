// #26 Remove Duplicates from Sorted Array
//
// Given a sorted array, remove the duplicates in place such that each element
// appear only once and return the new length.
//
// Do not allocate extra space for another array, you must do this in place
// with constant memory.
//
// For example,
// Given input array A = [1,1,2],
//
// Your function should return length = 2, and A is now [1,2].


#include <iostream>

class Solution {

  public:
    int removeDuplicates(int A[], int n)
    {
        if (1 >= n) {
            return n;
        }

        int pos = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1]) {
                A[pos++] = A[i];
            }
        }
        return pos;
    }
};

int main()
{
    int array1[] = { 1 };
    int array2[] = { 1, 2 };
    int array3[] = { 1, 1, 2 };
    int array4[] = { 1, 2, 2 };
    int array5[] = { 1, 2, 2, 3 };

    Solution s;

    std::cout << s.removeDuplicates(array1, sizeof array1 / sizeof(int))
              << std::endl;
    std::cout << s.removeDuplicates(array2, sizeof array2 / sizeof(int))
              << std::endl;
    std::cout << s.removeDuplicates(array3, sizeof array3 / sizeof(int))
              << std::endl;
    std::cout << s.removeDuplicates(array4, sizeof array4 / sizeof(int))
              << std::endl;
    std::cout << s.removeDuplicates(array5, sizeof array5 / sizeof(int))
              << std::endl;
    return 0;
}
