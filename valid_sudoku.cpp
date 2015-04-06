// #36 Valid Sudoku
//
// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
// The Sudoku board could be partially filled, where empty cells are filled
// with the character '.'.
//
// A partially filled sudoku which is valid.
//
// Note:
// A valid Sudoku board (partially filled) is not necessarily solvable. Only
// the filled cells need to be validated.


#include <iostream>
#include <vector>

class Solution {

  public:
    bool isValidSudoku(const std::vector<std::vector<char> >& board)
    {
        // Validate sudoku size

        if (9 != board.size()) {
            return false;
        }
        for (int i = 0; i < board.size(); ++i) {
            if (9 != board[i].size()) {
                return false;
            }
        }

        // Validate each row.

        for (int i = 0; i < 9; ++i) {
            std::vector<bool> map(9, false);
            for (int j = 0; j < 9; ++j) {
                if ('.' != board[i][j]) {
                    if (map[board[i][j] - '1']) {
                        // This number is already used, so this is an invalid
                        // sudoku.
                        return false;
                    }
                    map[board[i][j] - '1'] = true;
                }
            }
        }

        // Validate each column.

        for (int i = 0; i < 9; ++i) {
            std::vector<bool> map(9, false);
            for (int j = 0; j < 9; ++j) {
                if ('.' != board[j][i]) {
                    if (map[board[j][i] - '1']) {
                        // This number is already used, so this is an invalid
                        // sudoku.
                        return false;
                    }
                    map[board[j][i] - '1'] = true;
                }
            }
        }

        // Validate each sub board.

        for (int k = 0; k < 9; ++k) {
            std::vector<bool> map(9, false);
            int m = k * 3 % 9;
            int n = k / 3 * 3;
            for (int i = m; i < m + 3; ++i) {
                for (int j = n; j < n + 3; ++j) {
                    if ('.' != board[j][i]) {
                        if (map[board[j][i] - '1']) {
                            // This number is already used, so this is an
                            // invalid sudoku.
                            return false;
                        }
                        map[board[j][i] - '1'] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{
    char A[9][9] = {
        { '5', '3', '4', '6', '7', '8', '9', '1', '2' },
        { '6', '7', '2', '1', '9', '5', '3', '4', '8' },
        { '1', '9', '8', '3', '4', '2', '5', '6', '7' },
        { '8', '5', '9', '7', '6', '1', '4', '2', '3' },
        { '4', '2', '6', '8', '5', '3', '7', '9', '1' },
        { '7', '1', '3', '9', '2', '4', '8', '5', '6' },
        { '9', '6', '1', '5', '3', '7', '2', '8', '4' },
        { '2', '8', '7', '4', '1', '9', '6', '3', '5' },
        { '3', '4', '5', '2', '8', '6', '1', '7', '9' },
    };

    std::vector<std::vector<char> > board(9, std::vector<char>(9));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = A[i][j];
        }
    }

    Solution s;
    std::cout << s.isValidSudoku(board) << std::endl;
    return 0;
}
