// #75 Sort Colors
//
// Given an array with n objects colored red, white or blue, sort them so that
// objects of the same color are adjacent, with the colors in the order red,
// white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red,
// white, and blue respectively.
//
// Note:
//
// You are not suppose to use the library's sort function for this problem.
//
// Follow up:
//
// A rather straight forward solution is a two-pass algorithm using counting
// sort.
//
// First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.
//
// Could you come up with an one-pass algorithm using only constant space?


#include <iostream>

void print(int A[], int n)
{
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

class Solution_TwoPasses {

  public:
    void sortColors(int A[], int n)
    {
        int red   = 0;
        int white = 0;
        int blue  = 0;

        for (int i = 0; i < n; ++i) {
            if (0 == A[i]) {
                ++red;
            } else if (1 == A[i]) {
                ++white;
            } else {
                ++blue;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (red > 0) {
                A[i] = 0;
                --red;
            } else if (white > 0) {
                A[i] = 1;
                --white;
            } else {
                A[i] = 2;
                --blue;
            }
        }
    }
};

class Solution {

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

  public:
    void sortColors(int A[], int n)
    {
        int redIndex  = 0;
        int blueIndex = n - 1;

        for (int i = 0; i <= blueIndex;) {
            if (0 == A[i]) {
                // A[i] is red
                swap(&A[redIndex], &A[i]);
                ++redIndex;
                ++i; // we could increment i since A[redIndex] should be white.
            } else if (2 == A[i]) {
                // A[i] is blue
                swap(&A[blueIndex], &A[i]);
                --blueIndex;
                // we can't increment i since A[blueIndex] could be red.
            } else {
                // A[i] is white
                ++i;
            }
        }
    }
};

using namespace std;

class Solution1 {
public:
    void sortColors(int A[], int n) {
        int start = 0, end = n - 1;
        int i = 0;
        while (i < end) {
            if (0 == A[i]) swap(A[i++], A[start++]);
            else if (1 == A[i]) ++i;
            else swap(A[i], A[end--]);
        }
    }
};

int main()
{
    Solution1 s;

    int A[] = { 1, 2, 0 };
    s.sortColors(A, sizeof A / sizeof *A);
    print(A, sizeof A / sizeof *A);

    return 0;
}
