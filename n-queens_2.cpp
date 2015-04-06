// #52 N-Queens II
//
// Follow up for N-Queens problem.
//
// Now, instead outputting board configurations, return the total number of
// distinct solutions.


#include <vector>
#include <iostream>

class Solution {

    bool validate(const std::vector<int>& pos, int row)
        // Return 'true' if the queue placement at 'row' conflicts with the
        // queues at rows [0, row), and 'false' otherwise.
    {
        for (int i = 0; i < row; ++i) {
            if ((pos[i] == pos[row])
            ||  (row - i) == std::abs(pos[row] - pos[i]))
            {
                return false;
            }
        }
        return true;
    }

    void helper(int *count, std::vector<int>& pos, int row, int n)
    {
        if (n == row) {
            ++(*count);
            return;
        }

        // Try to place the queue at each column in the current 'row'.

        for (int col = 0; col < n; ++col) {
            pos[row] = col;
            if (validate(pos, row)) {
                helper(count, pos, row + 1, n);
            }
        }
    }

  public:
    int totalNQueens(int n)
    {
        int              count = 0;
        std::vector<int> pos(n, -1);
        helper(&count, pos, 0, n);
        return count;
    }
};

int main()
{
    Solution s;
    std::cout << s.totalNQueens(8) << std::endl;
    return 0;
}
