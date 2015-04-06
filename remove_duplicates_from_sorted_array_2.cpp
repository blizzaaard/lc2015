// #80 Remove Duplicates from Sorted Array II
//
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
// Given sorted array A = [1,1,1,2,2,3],
//
// Your function should return length = 5, and A is now [1,1,2,2,3].


#include <iostream>

class Solution {

  public:
    int removeDuplicates(int A[], int n)
    {
        if (1 >= n) {
            return n;
        }

        int pos   = 1;
        int count = 0;
        for (int i = 1; i < n; ++i) {
            if (A[i] != A[i - 1]) {
                A[pos++] = A[i];
                count = 0;
            } else {
                ++count;
                if (1 >= count) {
                    A[pos++] = A[i];
                }
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
    int array6[] = { 1, 1, 1, 2, 2, 3 };
    int array7[] = { 1, 1, 1, 2, 2, 3, 3, 3 };

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
    std::cout << s.removeDuplicates(array6, sizeof array6 / sizeof(int))
              << std::endl;
    std::cout << s.removeDuplicates(array7, sizeof array7 / sizeof(int))
              << std::endl;
    return 0;
}
