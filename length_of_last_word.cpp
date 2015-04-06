// #58 Length of Last Word
//
// Given a string s consists of upper/lower-case alphabets and empty space
// characters ' ', return the length of last word in the string.
//
// If the last word does not exist, return 0.
//
// Note: A word is defined as a character sequence consists of non-space
// characters only.
//
// For example,
//
// Given s = "Hello World",
//
// return 5.


#include <iostream>

class Solution {

  public:
    int lengthOfLastWord(const char *s)
    {
        int lastLength = 0;
        while (*s) {
            while (*s == ' ') {
                ++s;
            }
            int length = 0;
            while (*s && *s != ' ') {
                ++length;
                ++s;
            }
            if (0 != length) {
                lastLength = length;
            }
        }
        return lastLength;
    }
};

int main()
{
    Solution s;
    std::cout << s.lengthOfLastWord("Hello World") << std::endl;

    return 0;
}
