// #27 Remove Element
//
// Given an array and a value, remove all instances of that value in place and
// return the new length.
//
// The order of elements can be changed. It doesn't matter what you leave
// beyond the new length.


#include <iostream>

class Solution {

  public:
    int removeElement(int A[], int n, int elem) {
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (elem != A[i]) {
                A[index] = A[i];
                ++index;
            } 
        }
        return index;
    }
};

int main()
{
    int A[] = { 0, 1, 2, 2, 3 };
    Solution s;
    std::cout << s.removeElement(A, sizeof A / sizeof *A, 2) << std::endl;
    return 0;
}
