// #87 Scramble String
//
// Given a string s1, we may represent it as a binary tree by partitioning it
// to two non-empty substrings recursively.
//
// Below is one possible representation of s1 = "great":
//
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two
// children.
//
// For example, if we choose the node "gr" and swap its two children, it
// produces a scrambled string "rgeat".
//
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that "rgeat" is a scrambled string of "great".
//
// Similarly, if we continue to swap the children of nodes "eat" and "at", it
// produces a scrambled string "rgtae".
//
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that "rgtae" is a scrambled string of "great".
//
// Given two strings s1 and s2 of the same length, determine if s2 is a
// scrambled string of s1.


#include <iostream>

class Solution {

  public:
    bool isScramble(const std::string& s1, const std::string& s2)
    {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }

        // This is an optimization.  We check if the sum of the two strings is
        // the same before checking the actual charactors.

        int sum1 = 0;
        int sum2 = 0;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            sum1 += s1[i];
            sum2 += s2[i];
        }
        if (sum1 != sum2) {
            return false;
        }

        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i))
            &&  isScramble(s1.substr(i),    s2.substr(i)))
            {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i))
            &&  isScramble(s1.substr(i),    s2.substr(0, n - i)))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    std::cout << s.isScramble("rgeat", "great") << std::endl;
    std::cout << s.isScramble("rgtae", "great") << std::endl;
    return 0;
}
