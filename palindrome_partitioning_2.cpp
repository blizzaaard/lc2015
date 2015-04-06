// #132 Palindrome Partitioning II
//
// Given a string s, partition s such that every substring of the partition is
// a palindrome.
//
// Return the minimum cuts needed for a palindrome partitioning of s.
//
// For example, given s = "aab",
//
// Return 1 since the palindrome partitioning ["aa","b"] could be produced
// using 1 cut.


#include <vector>
#include <string>
#include <iostream>

class Solution {

    bool isPalindrome(const std::string& s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

  public:
    int minCut(const std::string& s)
    {
        std::vector<std::vector<bool> > optPal(s.size(),
                                               std::vector<bool>(s.size(),
                                                                 false));
        std::vector<int>                optCut(s.size() + 1);
        for (int i = 0; i < optCut.size(); ++i) {
            optCut[i] = i - 1;
        }
        for (int i = 0; i < s.size(); ++i) {
            // When we add a 'n' into 'xxxxx' we need to check each partition,
            // and find the one with minimum cut.
            //
            // e.g. when i = 5
            //
            // xxxxx n    (k = 5)
            // xxxx xn    (k = 4)
            // xxx xxn    (k = 3)
            // xx xxxn    (k = 2)
            // x xxxxn    (k = 1)
            //  xxxxxn    (k = 0)

            for (int k = i; k >= 0; --k) {
                if ((s[k] == s[i]) && (i - k < 2 || optPal[k + 1][i - 1])) {
                    // e.g. i = 7, k = 1
                    //
                    // xxxxxxxn
                    //  k     i
                    //   +---+
                    //     |
                    //     V
                    // we should already know if this part is a palindrome or
                    // not (it's optPal[k + 1][i - 1])

                    optCut[i + 1] = std::min(optCut[i + 1], optCut[k] + 1);
                    optPal[k][i] = true;
                }
            }
        }
        return optCut[s.size()];
    }
};

int main()
{
    Solution s;
    std::cout << s.minCut("aab") << std::endl;
    std::cout << s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
    return 0;
}
