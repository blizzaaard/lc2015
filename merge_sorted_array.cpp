// #88 Merge Sorted Array
//
// Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
// Note:
//
// You may assume that A has enough space (size that is greater or equal to m +
// n) to hold additional elements from B. The number of elements initialized in
// A and B are m and n respectively.


#include <iostream>

void print(int A[], int m)
{
    for (int i = 0; i < m; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    void merge(int A[], int m, int B[], int n)
    {
        int index  = m + n - 1;
        int indexA = m - 1;
        int indexB = n - 1;
        while (indexA >= 0 && indexB >= 0) {
            if (A[indexA] > B[indexB]) A[index--] = A[indexA--];
            else                       A[index--] = B[indexB--];
        }
        while (indexA >= 0) A[index--] = A[indexA--];
        while (indexB >= 0) A[index--] = B[indexB--];
    }
};

int main()
{
    Solution s;

    int A[] = { 1, 3, 5, 7, 9, 0, 0, 0, 0, 0 };
    int B[] = { 0, 2, 4, 6, 8 };
    s.merge(A, 5, B, 5);
    print(A, 10);

    return 0;
}
