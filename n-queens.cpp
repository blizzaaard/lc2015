// #51 N-Queens
//
// The n-queens puzzle is the problem of placing n queens on an n×n chessboard
// such that no two queens attack each other.
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space
// respectively.
//
// For example,
//
// There exist two distinct solutions to the 4-queens puzzle:
//
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]


#include <string>
#include <vector>
#include <iostream>

void print(const std::vector<std::vector<std::string> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << i + 1 << std::endl;
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << std::endl;
        }
        std::cout << std::endl;
    }
}

class Solution {

    void dump(std::vector<std::string> *result,
              const std::vector<int>&   pos)
    {
        const int n = pos.size();

        for (int i = 0; i < n; ++i) {
            std::string temp(n, '.');
            temp[pos[i]] = 'Q';
            result->push_back(temp);
        }
    }

    bool validate(const std::vector<int>& pos, int row)
        // Return 'true' if the queue placement at 'row' conflicts with the
        // queues at rows [0, row), and 'false' otherwise.
    {
        for (int i = 0; i < row; ++i) {
            if ((pos[i]   == pos[row])
            ||  (row - i) == std::abs(pos[row] - pos[i]))
            {
                return false;
            }
        }
        return true;
    }

    void helper(std::vector<std::vector<std::string> > *res,
                std::vector<int>&                       pos,
                int                                     row,
                int                                     n)
    {
        if (row == n) {
            std::vector<std::string> temp;
            dump(&temp, pos);
            res->push_back(temp);
            return;
        }

        // Try to place the queue at each column in the current 'row'.

        for (int col = 0; col < n; ++col) {
            pos[row] = col;
            if (validate(pos, row)) {
                helper(res, pos, row + 1, n);
            }
        }
    }

  public:
    std::vector<std::vector<std::string> > solveNQueens(int n)
    {
        std::vector<std::vector<std::string> > result;
        std::vector<int> pos(n, -1);
        helper(&result, pos, 0, n);
        return result;
    }
};

using namespace std;

class Solution1 {

    vector<string> toString(const vector<int>& solution)
    {
        int n = solution.size();
        vector<string> result(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            result[i][solution[i]] = 'Q';
        }
        return result;
    }

    bool isValid(const vector<int>& solution, int row)
    {
        for (int i = 0; i < row; ++i) {
            if (solution[i] == solution[row]) return false;
            if (row - i == abs(solution[row] - solution[i])) return false;
        }
        return true;
    }

    void helper(vector<vector<string> > &result, vector<int>& solution, int row, int n)
    {
        if (row >= n) {
            result.push_back(toString(solution));
            return;
        }
        for (int col = 0; col < n; ++col) {
            solution[row] = col;
            if (isValid(solution, row)) {
                helper(result, solution, row + 1, n);
            }
            solution[row] = -1;
        }
    }

  public:
    vector<vector<string> > solveNQueens(int n)
    {
        vector<vector<string> > result;
        vector<int>             solution(n, -1);
        helper(result, solution, 0, n);
        return result;
    }
};

int main()
{
    Solution1 s;
    print(s.solveNQueens(1));
//    print(s.solveNQueens(8));
    return 0;
}
