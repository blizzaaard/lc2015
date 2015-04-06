// #64 Minimum Path Sum
//
// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right which minimizes the sum of all numbers along its path.
//
// Note: You can only move either down or right at any point in time.


#include <iostream>
#include <vector>

class Solution {

  public:
    int minPathSum(const std::vector<std::vector<int> >& grid)
    {
        int m = grid.size();
        if (0 == m) {
            return 0;
        }
        int n = grid[0].size();
        if (0 == n) {
            return 0;
        }

        std::vector<std::vector<int> > opt(m, std::vector<int>(n, 0));

        // Base case

        opt[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            opt[i][0] = opt[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            opt[0][j] = opt[0][j - 1] + grid[0][j];
        }

        // opt[i][j] = min(opt[i - 1][j], opt[i][j - 1]) + grid[i][j]

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = std::min(opt[i - 1][j], opt[i][j - 1]) + grid[i][j];
            }
        }

        return opt[m - 1][n - 1];
    }
};

int main()
{
    Solution s;

    std::vector<std::vector<int> > grid(1, std::vector<int>(1, 0));
    grid[0][0] = 1;
    std::cout << s.minPathSum(grid) << std::endl;

    return 0;
}
