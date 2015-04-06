// #79 Word Search
//
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring. The
// same letter cell may not be used more than once.
//
// For example,
//
// Given board =
//
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
//
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.


#include <iostream>
#include <vector>

class Solution {

    bool search(std::vector<std::vector<char> > *board,
                int                              i,
                int                              j,
                const std::string&               word,
                int                              index)
    {
        if (index >= word.size()) {
            return true;
        }
        if (i < 0 || i >= board->size() || j < 0 || j >= (*board)[i].size()) {
            return false;
        }
        if ((*board)[i][j] != word[index]) {
            return false;
        }

        // Set the current visited item to be '#' so that it won't be visited
        // again

        char c = (*board)[i][j];
        (*board)[i][j] = '#';

        bool flag = search(board, i, j - 1, word, index + 1)
                 || search(board, i, j + 1, word, index + 1)
                 || search(board, i - 1, j, word, index + 1)
                 || search(board ,i + 1, j, word, index + 1);

        (*board)[i][j] = c;

        return flag;
    }

  public:
    bool exist(std::vector<std::vector<char> >& board, const std::string& word)
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (search(&board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;

    char A[3][4] = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' },
    };

    std::vector<std::vector<char> > board(3, std::vector<char>(4, 0));
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            board[i][j] = A[i][j];
        }
    }

    std::cout << s.exist(board, "ABCCED") << std::endl;
    std::cout << s.exist(board, "SEE") << std::endl;
    std::cout << s.exist(board, "ABCB") << std::endl;

    return 0;
}
