// #7 Reverse Integer
//
// Reverse digits of an integer.
//
// Example1: x = 123, return 321
// Example2: x = -123, return -321
//
// Have you thought about this?
// Here are some good questions to ask before coding. Bonus points for you if
// you have already thought through this!
//
// If the integer's last digit is 0, what should the output be? ie, cases such
// as 10, 100.
//
// Did you notice that the reversed integer might overflow? Assume the input is
// a 32-bit integer, then the reverse of 1000000003 overflows. How should you
// handle such cases?
//
// For the purpose of this problem, assume that your function returns 0 when
// the reversed integer overflows.
//
// Update (2014-11-10):
// Test cases had been added to test the overflow behavior.


#include <iostream>

class Solution {
  public:
    int reverse(int x)
    {
        unsigned int ux    = x < 0 ? -x : x;
        unsigned int limit = x < 0 ? INT_MAX + 1 : INT_MAX;
        unsigned int res = 0;
        while (ux) {
            if (limit / 10 < res) {
                return 0;
            }
            res *= 10;

            unsigned int digit = ux % 10;
            if (limit - digit < res) {
                return 0;
            }
            res += digit;

            ux /= 10;
        }
        return x < 0 ? -res : res;
    }
};

int main()
{
    {
        int x = INT_MIN;
        unsigned int ux = -x;
        std::cout << ux << std::endl;
    }

    {
        unsigned int x = INT_MAX + 1;
        std::cout << x << std::endl;
    }

    Solution s;
    std::cout << s.reverse(1534236469) << std::endl;
    std::cout << s.reverse(INT_MAX) << std::endl;
    std::cout << s.reverse(INT_MIN) << std::endl;

    return 0;
}
