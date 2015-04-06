// #125 Valid Palindrome
//
// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
//
// For example,
//
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
//
// Note:
//
// Have you consider that the string might be empty? This is a good question to
// ask during an interview.
//
// For the purpose of this problem, we define empty string as valid palindrome.


#include <cctype>
#include <iostream>
#include <string>

class Solution {

  public:
    bool isPalindrome(const std::string& s)
    {
        if (s.empty()) {
            return true;
        }
        int left  = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!std::isalpha(s[left]) && !std::isdigit(s[left])) {
                ++left;
                continue;
            } else if (!std::isalpha(s[right]) && !std::isdigit(s[right])) {
                --right;
                continue;
            }
            if (s[left] == s[right] || 32 == std::abs(s[left] - s[right])) {
                ++left;
                --right;
                continue;
            }
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    {
        std::cout << s.isPalindrome("A man, a plan, a canal: Panama")
                  << std::endl;
        std::cout << s.isPalindrome("race a car")
                  << std::endl;
    }
    return 0;
}
