// #97 Interleaving String
//
// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
// s2.
//
// For example,
// Given:
// s1 = "aabcc",
// s2 = "dbbca",
//
// When s3 = "aadbbcbcac", return true.
// When s3 = "aadbbbaccc", return false.


#include <string>
#include <vector>
#include <iostream>

class Solution_Recursion {

    bool helper(const std::string& s1,
                const std::string& s2,
                const std::string& s3,
                int                i,
                int                j,
                int                k)
    {
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }
        if (i < s1.size() && s3[k] == s1[i] && helper(s1, s2, s3, i + 1, j, k + 1)) {
            return true;
        }
        if (j < s2.size() && s3[k] == s2[j] && helper(s1, s2, s3, i, j + 1, k + 1)) {
            return true;
        }
        return false;
    }

  public:
    bool isInterleave(const std::string& s1,
                      const std::string& s2,
                      const std::string& s3)
    {
        return helper(s1, s2, s3, 0, 0, 0);
    }
};

class Solution {

  public:
    bool isInterleave(const std::string& s1,
                      const std::string& s2,
                      const std::string& s3)
    {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) return false;

        // We add one more element to the matrix to handle the empty strings
        // more easily.
        //
        // opt(i, j) denotes if s1(0, i) and s2(0, j) is interleaving strings
        // of s3(0, i + j)

        std::vector<std::vector<bool> > opt(
                                    m + 1, std::vector<bool>(n + 1, false));
        opt[0][0] = true;

        // s1 = "adc"
        // s2 = ""
        // s3 = "abc"
        //
        // opt[i][0] is 'true' iff s1(0, i) and s3(0, i) are the same.

        for (int i = 1; i < m + 1; ++i) {
            opt[i][0] = opt[i - 1][0] && s3[i - 1] == s1[i - 1];
        }

        // s1 = ""
        // s2 = "adc"
        // s3 = "abc"
        //
        // opt[0][j] is 'true' iff s1(0, j) and s3(0, j) are the same.

        for (int j = 1; j < n + 1; ++j) {
            opt[0][j] = opt[0][j - 1] && s3[j - 1] == s2[j - 1];
        }

        // opt(i, j): s1(0, i - 1)
        //            s2(0, j - 1)
        //            s3(0, i + j - 1)
        //
        // opt(i, j) = opt(i - 1, j) when s1[i - 1] == s3[i + j - 1]
        //          or opt(i, j - 1) when s2[j - 1] == s3[i + j - 1]

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int k = i + j;
                if (s3[k - 1] == s1[i - 1]) {
                    // Since s1[i - 1] matches s3[k - 1], we need to check if
                    // s1[:i - 2] and s2[:j - 1] (denoted by opt[i - 1][j]) are
                    // interleaving substrings of s3[k - 2].

                    opt[i][j] = opt[i - 1][j];
                }
                if (opt[i][j]) {
                    // Since s1[i - 1] matched s3[k - 1], we don't need to
                    // check s2[:j - 1].

                    continue;
                }
                if (s3[k - 1] == s2[j - 1]) {
                    // Since s2[j - 1] matches s3[k - 1], we need to check if
                    // s1[:i - 1] and s2[:j - 2] (denoted by opt[i][j - 1]) are
                    // interleaving substrings of s3[k - 2].

                    opt[i][j] = opt[i][j - 1];
                }
            }
        }
        return opt[m][n];
    }
};

int main()
{
    Solution_Recursion sr;

    // This test case is not covered by LeetCode
    std::cout << sr.isInterleave("", "abc", "abc") << std::endl;
    std::cout << sr.isInterleave("adc", "", "abc") << std::endl;

    Solution s;

    // This test case is not covered by LeetCode
    std::cout << s.isInterleave("", "abc", "abc") << std::endl;
    std::cout << s.isInterleave("adc", "", "abc") << std::endl;

    return 0;
}
