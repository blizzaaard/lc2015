// #200 Number of Islands
//
// Given a 2d grid map of '1's (land) and '0's (water), count the number of
// islands. An island is surrounded by water and is formed by connecting
// adjacent lands horizontally or vertically. You may assume all four edges of
// the grid are all surrounded by water.
//
// Example 1:
//
// 11110
// 11010
// 11000
// 00000
//
// Answer: 1
//
// Example 2:
//
// 11000
// 11000
// 00100
// 00011
//
// Answer: 3

class Solution {

    bool helper(vector<vector<char> >& grid, int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if ('1' == grid[i][j]) {
            grid[i][j] = '2';
            helper(grid, i + 1, j, m, n);
            helper(grid, i - 1, j, m, n);
            helper(grid, i, j - 1, m, n);
            helper(grid, i, j + 1, m, n);
            return true;
        }
        return false;
    }

  public:
    int numIslands(vector<vector<char> >& grid)
    {
        int count = 0;
        int m = grid.size();
        if (0 == m) return count;
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (helper(grid, i, j, m, n)) ++count;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('2' == grid[i][j]) grid[i][j] = '1';
            }
        }
        return count;
    }
};
