// #9 Palindrome Number
//
// Determine whether an integer is a palindrome. Do this without extra space.
//
// Some hints:
// Could negative integers be palindromes? (ie, -1)
//
// If you are thinking of converting the integer to string, note the
// restriction of using extra space.
//
// You could also try reversing an integer. However, if you have solved the
// problem "Reverse Integer", you know that the reversed integer might
// overflow. How would you handle such case?
//
// There is a more generic way of solving this problem.


#include <iostream>

class Solution {
  public:
    bool isPalindrome(int x)
    {
        if (0 > x) {
            return false;
        }

        int digits = 1;
        while (x / digits >= 10) {
            digits *= 10;
        }

        while (x) {
            int left  = x / digits;
            int right = x % 10;

            if (left != right) {
                return false;
            }

            x = (x % digits) / 10; // convert from abcde to bcd

            digits /= 100; // 2 digits were removed
        }
        return true;
    }
};

int main()
{
    Solution s;
    std::cout << s.isPalindrome(12321) << std::endl;
    std::cout << s.isPalindrome(INT_MAX) << std::endl;
    std::cout << s.isPalindrome(INT_MIN) << std::endl;

    return 0;
}
