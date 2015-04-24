// #54 Spiral Matrix
//
// Given a matrix of m x n elements (m rows, n columns), return all elements of
// the matrix in spiral order.
//
// For example,
//
// Given the following matrix:
//
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// You should return [1,2,3,6,9,8,7,4,5].


#include <vector>
#include <iostream>

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int> >& matrix)
    {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }

        int topBound    = 0;
        int bottomBound = matrix.size() - 1;
        int leftBound   = 0;
        int rightBound  = matrix[0].size() - 1;

        int state = 0;
            // 0 - right; 1 - down; 2 - left; 3 - up
        int i = 0;
        int j = 0;

        while (1) {
            if (topBound > bottomBound && leftBound > rightBound) {
                break;
            }

            // When we hit the bound

            if (j > rightBound) {
                state = 1; // down
                --j;
                ++i;
                ++topBound;
                continue;
            } else if (i > bottomBound) {
                state = 2; // left
                --i;
                --j;
                --rightBound;
                continue;
            } else if (j < leftBound) {
                state = 3; // up
                ++j;
                --i;
                --bottomBound;
                continue;
            } else if (i < topBound) {
                state = 0; // right
                ++i;
                ++j;
                ++leftBound;
                continue;
            }

            // When we haven't hit the bound

            result.push_back(matrix[i][j]);

            if (0 == state) { // right
                ++j;
            } else if (1 == state) { // down
                ++i;
            } else if (2 == state) { // left
                --j;
            } else if (3 == state) { // up
                --i;
            }
        }
        return result;
    }
};

using namespace std;

class Solution1 {

  public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
    {
        vector<int> result;
        int m = matrix.size();
        if (0 == m) return result;
        int n = matrix[0].size();
        int i = 0, j = 0, state = 0;
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            if (j > right) {
                --j; ++i; state = 1; ++top;
            } else if (i > bottom) {
                --i; --j; state = 2; --right;
            } else if (j < left) {
                ++j; --i; state = 3; --bottom;
            } else if (i < top) {
                ++i; ++j; state = 0; ++left;
            } else {
                result.push_back(matrix[i][j]);
                if (0 == state) ++j;
                else if (1 == state) ++i;
                else if (2 == state) --j;
                else if (3 == state) --i;
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    {
        std::vector<std::vector<int> > matrix(3, std::vector<int>(3, 0));
        int k = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = ++k;
            }
        }
        print(s.spiralOrder(matrix));
    }
    {
        std::vector<std::vector<int> > matrix(1, std::vector<int>(2, 0));
        int k = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = ++k;
            }
        }
        print(s.spiralOrder(matrix));
    }
    {
        std::vector<std::vector<int> > matrix(1, std::vector<int>(1, 0));
        int k = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = ++k;
            }
        }
        print(s.spiralOrder(matrix));
    }

    return 0;
}
