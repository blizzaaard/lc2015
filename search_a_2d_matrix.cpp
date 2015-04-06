// #74 Search a 2D Matrix
//
// Write an efficient algorithm that searches for a value in an m x n matrix.
// This matrix has the following properties:
//
// Integers in each row are sorted from left to right.
//
// The first integer of each row is greater than the last integer of the
// previous row.
//
// For example,
//
// Consider the following matrix:
//
// [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
//
// Given target = 3, return true.


#include <iostream>
#include <vector>

class Solution1 {
    // Time complexity: O(mn)

  public:
    bool searchMatrix(const std::vector<std::vector<int> >& matrix, int target)
    {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution2 {
    // Time complexity: O(m + n)

  public:
    bool searchMatrix(const std::vector<std::vector<int> >& matrix, int target)
    {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n - 1;
        while (i >= 0 && i < m && j >= 0 && j < n) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

class Solution {
    // Time complexity: O(lgm + lgn)

  public:
    bool searchMatrix(const std::vector<std::vector<int> >& matrix, int target)
    {
        int row = -1;

        // Find the row of the target number.

        int m = matrix.size();

        int start = 0;
        int end   = m - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid == m - 1
            ||  (matrix[mid][0] <= target && target < matrix[mid + 1][0]))
            {
                row = mid;
                break;
            } else if (matrix[mid + 1][0] <= target) {
                start = mid + 1;
            } else {
                end   = mid - 1;
            }
        }

        if (-1 == row) {
            return false;
        }

        // Find the column of the target number in the row.

        int n = matrix[0].size();

        start = 0;
        end   = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid + 1;
            } else {
                end   = mid - 1;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;

    int A[3][4] = {
        { 1,   3,  5,  7 },
        { 10, 11, 16, 20 },
        { 23, 30, 34, 50 },
    };

    std::vector<std::vector<int> > matrix(3, std::vector<int>(4, 0));
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = A[i][j];
        }
    }

    std::cout << s.searchMatrix(matrix, 3) << std::endl;

    return 0;
}
