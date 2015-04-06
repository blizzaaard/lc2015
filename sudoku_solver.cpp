#include <vector>
#include <iostream>

class Solution {
  public:
    std::vector<std::vector<bool> > m_row;
    std::vector<std::vector<bool> > m_col;
    std::vector<std::vector<bool> > m_sub;

    void print(const std::vector<std::vector<char> >& board)
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                std::cout << board[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void set(std::vector<std::vector<char> > *board, int i, int j, int value, bool flag)
    {
        m_row[i][value - 1] = flag;
        m_col[j][value - 1] = flag;
        m_sub[i / 3 * 3 + j / 3][value - 1] = flag;
        (*board)[i][j] = flag ? (value + '0') : '.';
    }
    
    bool isValid(int i, int j, int value)
    {
        if (m_row[i][value - 1]
        ||  m_col[j][value - 1]
        ||  m_sub[i / 3 * 3 + j / 3][value - 1])
        {
            return false;
        }
        return true;
    }
    
    bool helper(std::vector<std::vector<char> > *board, int index)
    {
        if (index > 80) {
            return true;
        }
        int i = index / 9;
        int j = index % 9;

        //std::cout << index << " (" << i << ", " << j << ")" << std::endl;
        
        if ('.' != (*board)[i][j]) {
            return helper(board, index + 1);
        }
        
        for (int n = 1; n <= 9; ++n) {
            if (!isValid(i, j, n)) {
                continue;
            }
            set(board, i, j, n, true);
            if (helper(board, index + 1)) {
                //print(*board);
                return true;
            }
            set(board, i, j, n, false);
        }
        return false;
    }
    
    void solveSudoku(std::vector<std::vector<char> > &board)
    {
        m_row.resize(9, std::vector<bool>(9, false));
        m_col.resize(9, std::vector<bool>(9, false));
        m_sub.resize(9, std::vector<bool>(9, false));
    
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ('.' != board[i][j]) {
                    set(&board, i, j, board[i][j] - '0', true);
                }
            }
        }
        std::cout << helper(&board, 0) << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::vector<std::vector<char> > board(9, std::vector<char>(9, '.'));
    board[0][2] = '9'; board[0][3] = '7'; board[0][4] = '4'; board[0][5] = '8';
    board[1][0] = '7';
    board[2][1] = '2'; board[2][3] = '1'; board[2][5] = '9';
    board[3][2] = '7'; board[3][6] = '2'; board[3][7] = '4';
    board[4][1] = '6'; board[4][2] = '4'; board[4][4] = '1'; board[4][6] = '5'; board[4][7] = '9';
    board[5][1] = '9'; board[5][2] = '8'; board[5][6] = '3';
    board[6][3] = '8'; board[6][5] = '3'; board[6][7] = '2';
    board[7][8] = '6';
    board[8][3] = '2'; board[8][4] = '7'; board[8][5] = '5'; board[8][6] = '9';

    Solution s;
    s.solveSudoku(board);
    s.print(board);
    return 0;
}