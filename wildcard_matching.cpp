// #44 Wildcard Matching
//
// Implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
// The matching should cover the entire input string (not partial).
//
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
//
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "*") → true
// isMatch("aa", "a*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false


#include <iostream>

class Solution {

  public:
    bool isMatch(const char *s, const char *p)
    {
        const char *star = 0;
        const char *prev = 0;
        while (*s) {
            if ('?' == *p || *s == *p) {
                ++s;
                ++p;
            } else if ('*' == *p) {
                star = p;
                prev = s;
                ++p;
            } else if (star) {
                s = prev + 1;
                prev = s;
                p = star + 1;
            } else  {
                return false;
            }
        }
        while ('*' == *p) {
            ++p;
        }
        return !*p;
    }
};

int main()
{
    Solution s;
    std::cout << s.isMatch("aa","a") << std::endl;
    std::cout << s.isMatch("aa","aa") << std::endl;
    std::cout << s.isMatch("aaa","aa") << std::endl;
    std::cout << s.isMatch("aa", "*") << std::endl;
    std::cout << s.isMatch("aa", "a*") << std::endl;
    std::cout << s.isMatch("ab", "?*") << std::endl;
    std::cout << s.isMatch("aab", "c*a*b") << std::endl;
    return 0;
}
