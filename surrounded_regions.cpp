// #130 Surrounded Regions
//
// Given a 2D board containing 'X' and 'O', capture all regions surrounded by
// 'X'.
//
// A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
// For example,
//
// X X X X
// X O O X
// X X O X
// X O X X
//
// After running your function, the board should be:
//
// X X X X
// X X X X
// X X X X
// X O X X


#include <iostream>
#include <queue>
#include <vector>

void print(const std::vector<std::vector<char> >& board)
{
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

class Solution {

    void visit(std::vector<std::vector<char> > *board,
               int                              i,
               int                              j,
               int                              m,
               int                              n)
    {
        std::queue<std::pair<int, int> > queue;
        queue.push(std::make_pair(i, j));
        while (!queue.empty()) {
            std::pair<int, int> item = queue.front();
            queue.pop();
            int i = item.first;
            int j = item.second;
            if (i < 0 || i >= m || j < 0 || j >= n) {
                continue;
            }
            if ('O' == (*board)[i][j]) {
                (*board)[i][j] = 'Y';  // mark this can be reached from edge
                queue.push(std::make_pair(i - 1, j));
                queue.push(std::make_pair(i + 1, j));
                queue.push(std::make_pair(i, j - 1));
                queue.push(std::make_pair(i, j + 1));
            }
        }
    }

  public:
    void solve(std::vector<std::vector<char> >& board)
    {
        int m = board.size();
        if (0 == m) {
            return;
        }
        int n = board[0].size();
        if (0 == n) {
            return;
        }

        // Visit the nodes at the edge

        for (int i = 0; i < m; ++i) {
            visit(&board, i, 0, m, n);
            visit(&board, i, n - 1, m, n);
        }
        for (int j = 0; j < n; ++j) {
            visit(&board, 0, j, m, n);
            visit(&board, m - 1, j, m, n);
        }

        // Restore the board

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('Y' == board[i][j]) {
                    board[i][j] = 'O';
                } else if ('O' == board[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main()
{
    Solution s;
    {
        std::vector<std::vector<char> > board(4, std::vector<char>(4, 0));
        board[0][0]='X'; board[0][1]='X'; board[0][2]='X'; board[0][3]='X';
        board[1][0]='X'; board[1][1]='O'; board[1][2]='O'; board[1][3]='X';
        board[2][0]='X'; board[2][1]='X'; board[2][2]='O'; board[2][3]='X';
        board[3][0]='X'; board[3][1]='O'; board[3][2]='X'; board[3][3]='X';
        s.solve(board);
        print(board);
    }
    return 0;
}
