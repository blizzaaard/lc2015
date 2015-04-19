// #48 Rotate Image
//
// You are given an n x n 2D matrix representing an image.
//
// Rotate the image by 90 degrees (clockwise).
//
// Follow up:
//
// Could you do this in-place?


#include <iostream>
#include <vector>

void print(const std::vector<std::vector<int> >& matrix)
{
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {

    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

  public:
    void rotate(std::vector<std::vector<int> >& matrix)
    {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size();

        // A B  -->  C B
        // D C       D A

        for (int i = 0; i < m - 1; ++i) {
            for (int j = 0; j < m - 1 - i; ++j) {
                swap(&matrix[i][j], &matrix[m - 1 - j][m - 1 - i]);
            }
        }

        // C B  -->  D A
        // D A       C B

        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m - 1 - i][j];
                matrix[m - 1 - i][j] = temp;
            }
        }
    }
};

class Solution {

  public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
    }
};

int main()
{
    Solution s;

    int A[2][2] = {
        { 1, 2 },
        { 3, 4 },
    };

    std::vector<std::vector<int> > matrix(2, std::vector<int>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[i][j] = A[i][j];
        }
    }

    s.rotate(matrix);
    print(matrix);

    return 0;
}
