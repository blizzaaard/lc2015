// #120 Triangle
//
// Given a triangle, find the minimum path sum from top to bottom. Each step
// you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
//
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
// Note:
//
// Bonus point if you are able to do this using only O(n) extra space, where n
// is the total number of rows in the triangle.


#include <iostream>
#include <vector>

class Solution_OmnSpace {
    // O(mn) space

  public:
    int minimumTotal(const std::vector<std::vector<int> >& triangle)
    {
        if (triangle.empty()) {
            return 0;
        }
        std::vector<std::vector<int> > opt(triangle.size(),
                                           std::vector<int>());
        for (int i = 0; i < triangle.size(); ++i) {
            opt[i].resize(i + 1, 0);
        }

        // Base case

        opt[0][0] = triangle[0][0];

        for (int i = 1; i < opt.size(); ++i) {
            for (int j = 0; j < opt[i].size(); ++j) {
                if (0 == j) {
                    opt[i][j] = opt[i - 1][j];
                } else if (opt[i].size() - 1 == j) {
                    opt[i][j] = opt[i - 1][j - 1];
                } else {
                    opt[i][j] = std::min(opt[i - 1][j - 1], opt[i - 1][j]);
                }
                opt[i][j] += triangle[i][j];
            }
        }

        // Find the minimum total in the last row

        int lastRow = triangle.size() - 1;
        int minimum = opt[lastRow][0];
        for (int i = 1; i < opt[lastRow].size(); ++i) {
            minimum = std::min(minimum, opt[lastRow][i]);
        }

        return minimum;
    }
};

class Solution {
    // O(n) space

  public:
    int minimumTotal(std::vector<std::vector<int> >& triangle)
    {
        if (triangle.empty()) {
            return 0;
        }

        std::vector<int> opt(triangle.size(), 0);

        // Base case

        opt[0] = triangle[0][0];

        for (int i = 1; i < opt.size(); ++i) {
            int prev = 0;
            for (int j = 0; j < i + 1; ++j) {
                if (0 == j) {
                    prev = opt[j];
                } else if (i == j) {
                    opt[j] = prev;
                } else {
                    int newPrev = opt[j];
                    opt[j] = std::min(prev, opt[j]);
                    prev   = newPrev;
                }
                opt[j] += triangle[i][j];
            }
        }

        // Find the minimum total in the last row

        int minimum = opt[0];
        for (int j = 1; j < opt.size(); ++j) {
            minimum = std::min(minimum, opt[j]);
        }

        return minimum;
    }
};

int main()
{
    Solution_OmnSpace so;
    Solution          s;
    {
        std::vector<std::vector<int> > triangle(4);
        for (int i = 0; i < triangle.size(); ++i) {
            triangle[i].resize(i + 1, 0);
        }
        triangle[0][0] = 2;
        triangle[1][0] = 3; triangle[1][1] = 4;
        triangle[2][0] = 6; triangle[2][1] = 5; triangle[2][2] = 7;
        triangle[3][0] = 4; triangle[3][1] = 1;
        triangle[3][2] = 8; triangle[3][3] = 3;

        std::cout << so.minimumTotal(triangle) << std::endl;
        std::cout << s.minimumTotal(triangle) << std::endl;
    }
    return 0;
}
