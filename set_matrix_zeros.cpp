// #73 Set Matrix Zeroes
//
// Given a m x n matrix, if an element is 0, set its entire row and column to
// 0. Do it in place.
//
// Follow up:
//
// Did you use extra space?
//
// A straight forward solution using O(mn) space is probably a bad idea.
//
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?


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

  public:
    void setZeroes(std::vector<std::vector<int> >& matrix)
    {
        if (matrix.empty()) {
            return;
        }

        // Use two flags to mark if the first row and the first column has
        // zeros set.

        bool firstRow = false;
        bool firstCol = false;

        for (int i = 0; i < matrix.size(); ++i) {
            if (0 == matrix[i][0]) {
                firstCol = true;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (0 == matrix[0][j]) {
                firstRow = true;
                break;
            }
        }

        // Use the first row and the first column to store if a row or a colunm
        // has zeros set (set the first row or the first column to zero if
        // there's a zero in the row or the folumn).

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set the row to all zeros if the first item in the row is zero, and
        // set the column to all zeros if the first item in the column is zero.

        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (0 == matrix[0][j] || 0 == matrix[i][0]) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set the values in the first row and the first column.

        if (firstCol) {
            for (int i = 1; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
        if (firstRow) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

using namespace std;

class Solution1 {

  public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        if (0 == m) return;
        int n = matrix[0].size();
        if (0 == n) return;
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        for (int i = 0; i < m; ++i) {
            if (0 == matrix[i][0]) {
                zeroFirstCol = true;
                break;
            }
        }
        for (int j = 0; j < n; ++j) {
            if (0 == matrix[0][j]) {
                zeroFirstRow = true;
                break;
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][0] || 0 == matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if (zeroFirstCol) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (zeroFirstRow) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int> > matrix(3, std::vector<int>(3, 1));
    matrix[0][0] = 0;
    matrix[1][0] = 0;

    s.setZeroes(matrix);
    print(matrix);

    return 0;
}
