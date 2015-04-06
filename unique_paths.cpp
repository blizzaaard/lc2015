// #62 Unique Paths
//
// A robot is located at the top-left corner of a m x n grid (marked 'Start' in
// the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//
// Above is a 3 x 7 grid. How many possible unique paths are there?
//
// Note: m and n will be at most 100.


#include <vector>
#include <iostream>

class Solution {

  public:
    int uniquePaths(int m, int n)
    {
        if (0 == m || 0 == n) {
            return 0;
        }

        std::vector<std::vector<int> > opt(m, std::vector<int>(n, 0));

        // Base cases

        opt[0][0] = 1;
        for (int i = 1; i < m; ++i) {
            opt[i][0] = 1;
        }
        for (int j = 1; j < n; ++j) {
            opt[0][j] = 1;
        }

        // opt[i][j] = opt[i - 1][j] + opt[i][j - 1]

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
            }
        }

        return opt[m - 1][n - 1];
    }
};

int main()
{
    Solution s;
    std::cout << s.uniquePaths(1, 1) << std::endl;
    std::cout << s.uniquePaths(20, 20) << std::endl;
    return 0;
}
