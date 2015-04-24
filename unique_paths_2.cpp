// #63 Unique Paths II
//
// Follow up for "Unique Paths":
//
// Now consider if some obstacles are added to the grids. How many unique paths
// would there be?
//
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
// For example,
//
// There is one obstacle in the middle of a 3x3 grid as illustrated below.
//
// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.
//
// Note: m and n will be at most 100.


#include <iostream>
#include <vector>

class Solution {

  public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (0 == m) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if (0 == n) {
            return 0;
        }

        std::vector<std::vector<int> > opt(m, std::vector<int>(n, 0));

        // Base cases

        opt[0][0] = (0 == obstacleGrid[0][0]) ? 1 : 0;
        for (int i = 1; i < m; ++i) {
            opt[i][0] = 0 == obstacleGrid[i][0] ? opt[i - 1][0] : 0;
        }
        for (int j = 1; j < n; ++j) {
            opt[0][j] = 0 == obstacleGrid[0][j] ? opt[0][j - 1] : 0;
        }

        // opt[i][j] = opt[i-1][j] + opt[i][j-1] when obstacleGrid[i][j] == 0
        // opt[i][j] = 0                         when obstacleGrid[i][j] == 1

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = 0 == obstacleGrid[i][j]
                          ? opt[i - 1][j] + opt[i][j - 1]
                          : 0;
            }
        }

        return opt[m - 1][n - 1];
    }
};

using namespace std;

class Solution1 {

  public:
    int uniquePathsWithObstacles(vector<vector<int> > &grid)
    {
        int m = grid.size();
        if (0 == m) return 0;
        int n = grid[0].size();
        vector<vector<int> > opt(m, vector<int>(n, 0));
        opt[0][0] = 1 == grid[0][0] ? 0 : 1;
        for (int i = 1; i < m; ++i) {
            opt[i][0] = 1 == grid[i][0] ? 0 : opt[i - 1][0];
        }
        for (int j = 1; j < n; ++j) {
            opt[0][j] = 1 == grid[0][j] ? 0 : opt[0][j - 1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = 1 == grid[i][j] ? 0 : opt[i - 1][j] + opt[i][j - 1];
            }
        }
        return opt[m - 1][n - 1];
    }
};

int main()
{
    Solution1 s;

    {
        std::vector<std::vector<int> > grid(1, std::vector<int>(1, 0));
        grid[0][0] = 0;
        std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    }
    {
        std::vector<std::vector<int> > grid(3, std::vector<int>(3, 0));
        grid[1][1] = 1;
        std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    }
    {
        std::vector<std::vector<int> > grid(1, std::vector<int>(2, 0));
        grid[0][1] = 1;
        std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    }
    {
        std::vector<std::vector<int> > grid(2, std::vector<int>(2, 0));
        grid[1][0] = 1;
        std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    }

    return 0;
}
