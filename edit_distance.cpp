// #72 Edit Distance
//
// Given two words word1 and word2, find the minimum number of steps required
// to convert word1 to word2. (each operation is counted as 1 step.)
//
// You have the following 3 operations permitted on a word:
//
//   a) Insert a character
//   b) Delete a character
//   c) Replace a character


#include <iostream>
#include <string>
#include <vector>

class Solution {

  public:
    int minDistance(const std::string& word1, const std::string& word2)
    {
        // We add one more element to the matrix to handle the empty strings
        // more easily.

        std::vector<std::vector<int> > opt(
                    word1.size() + 1, std::vector<int>(word2.size() + 1, 0));

        // word1 = "abcde"
        // word2 = ""
        // word1 can be converted to word2 by removing every charactor.

        for (int i = 0; i < opt.size(); ++i) {
            opt[i][0] = i;
        }

        // word1 = ""
        // word2 = "abcde"
        // word1 can be converted to word2 by adding all missing charactor.

        for (int j = 0; j < opt[0].size(); ++j) {
            opt[0][j] = j;
        }

        // opt(i, j) = min(opt(i - 1, j) + 1, // by removing word1[i]
        //                 opt(i, j - 1) + 1, // by adding word2[j]
        //                 (
        //                 opt(i - 1, j - 1) + 1 // when word[i] != word[j]
        //                                       // by replacing word1[i] with
        //                                       // word2[j]
        //
        //              or opt(i - 1, j - 1)     // when word[i] == word[j]
        //                 )

        for (int i = 1; i < opt.size(); ++i) {
            for (int j = 1; j < opt[i].size(); ++j) {
                opt[i][j] = std::min(std::min(opt[i][j - 1] + 1,
                                              opt[i - 1][j] + 1),
                                     (word1[i - 1] == word2[j - 1]
                                            ? opt[i - 1][j - 1]
                                            : opt[i - 1][j - 1] + 1));
            }
        }

        return opt[word1.size()][word2.size()];
    }
};

class Solution {
    
  public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > opt(m + 1, vector<int>(n + 1, 0));
        
        // A: "abc"
        // B: ""
        for (int i = 0; i <= m; ++i) opt[i][0] = i;
        
        // A: ""
        // B: "abc"
        for (int j = 0; j <= n; ++j) opt[0][j] = j;
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                opt[i][j] = min(opt[i - 1][j] + 1, min(opt[i][j - 1] + 1, word1[i - 1] == word2[j - 1] ? opt[i - 1][j - 1] : opt[i - 1][j - 1] + 1));
            }
        }
        
        return opt[m][n];
    }
};

int main()
{
    Solution s;
    std::cout << s.minDistance("a", "b") << std::endl;
    return 0;
}
