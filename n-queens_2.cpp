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

using namespace std;

class Solution1 {

    bool isValid(const vector<int>& solution, int row)
    {
        for (int i = 0; i < row; ++i) {
            if (solution[i] == solution[row]) return false;
            if (row - i == abs(solution[row] - solution[i])) return false;
        }
        return true;
    }

    void helper(int& count, vector<int>& solution, int row, int n)
    {
        if (row >= n) {
            ++count;
            return;
        }
        for (int col = 0; col < n; ++col) {
            solution[row] = col;
            if (isValid(solution, row)) {
                helper(count, solution, row + 1, n);
            }
            solution[row] = -1;
        }
    }

  public:
    int totalNQueens(int n)
    {
        int count = 0;
        vector<int> solution(n, -1);
        helper(count, solution, 0, n);
        return count;
    }
};

int main()
{
    Solution1 s;
    std::cout << s.totalNQueens(8) << std::endl;
    return 0;
}
