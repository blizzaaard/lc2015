// #115 Distinct Subsequences
//
// Given a string S and a string T, count the number of distinct subsequences
// of T in S.
//
// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).
//
// Here is an example:
// S = "rabbbit", T = "rabbit"
//
// Return 3.


#include <iostream>
#include <vector>
#include <string>

class Solution {
  public:
    int numDistinct(const std::string& S, const std::string& T)
    {
        int m = S.size();
        int n = T.size();

        // We add one more element to the opt matrix to handle the empty string
        // more easily.

        std::vector<std::vector<int> > opt(m + 1, std::vector<int>(n + 1, 0));

        // S = ""
        // T = "rabbit"
        // T cannot be a substring of S since S is empty.

        for (int j = 0; j <= n; ++j) {
            opt[0][j] = 0;
        }

        // S = "rabbit"
        // T = ""
        // T is always a substring of S when we remove any charactors from S.

        for (int i = 0; i <= m; ++i) {
            opt[i][0] = 1;
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    // We have 2 options when S[i - 1] and T[j - 1] are the
                    // same.
                    //   1. Since S[i - 1] == T[j - 1], we do not remove
                    //      S[i - 1] from S (keep this charactor in the result
                    //      string so S[i - 1] matches T[j - 1]).  The result
                    //      would be opt[i - 1][j - 1]
                    //
                    //   2. Even if S[i - 1] == T[j - 1], we still want to try
                    //      removing S[i - 1] from S (so S[i - 1] doesn't match
                    //      T[j - 1]).  The result would be opt[i - 1][j]

                    opt[i][j] = opt[i - 1][j - 1] + opt[i - 1][j];
                } else {
                    // When S[i - 1] != T[j - 1], we have only one option.  We
                    // cannot leave S[i - i] because it doesn't match T[j - 1]

                    opt[i][j] = opt[i - 1][j];
                }
            }
        }
        return opt[m][n];
    }
};

int main()
{
    Solution s;
    std::cout << s.numDistinct("rabbbit", "rabbit") << std::endl;
    std::cout << s.numDistinct("b", "a") << std::endl;
    return 0;
}
