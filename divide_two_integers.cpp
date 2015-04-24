// #29 Divide Two Integers
//
// Divide two integers without using multiplication, division and mod operator.
//
// If it is overflow, return MAX_INT.


#include <iostream>

class Solution {

  public:
    int divide(int dividend, int divisor)
    {
        unsigned int udividend = dividend < 0 ? -dividend : dividend;
        unsigned int udivisor  = divisor  < 0 ? -divisor  : divisor;

        unsigned int res = 0;
        while (udividend > 0 && udividend >= udivisor) {
            unsigned int localRes = 1;
            unsigned int temp     = udivisor;
            while ((INT_MAX >> 1 >= temp)    // temp * 2 won't overflow
                && (temp << 1 <= udividend)) // temp * 2 is <= 'udividend'
            {
                localRes = localRes << 1;
                temp     = temp     << 1;
            }
            res += localRes;
            udividend -= temp;
        }
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) {
            if (INT_MAX < res) {
                return INT_MAX;
            }
            return res;
        } else {
            return -res;
        }
    }
};

class Solution1 {

  public:
    int divide(int dividend, int divisor)
    {
        unsigned int udividend = dividend > 0 ? dividend : -dividend;
        unsigned int udivisor  = divisor  > 0 ? divisor  : -divisor;
        unsigned int result = 0;
        while (udividend >= udivisor) {
            unsigned int tempDiv = udivisor;
            unsigned int tempRes = 1;
            while (udividend - tempDiv >= tempDiv) {
                tempDiv <<= 1;
                tempRes <<= 1;
            }
            udividend -= tempDiv;
            result    += tempRes;
        }
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) {
            if (result > INT_MAX) return INT_MAX;
            else return result;
        } else {
            if (result - 1 > INT_MAX) return INT_MAX;
            else return -result;
        }
    }
};

int main()
{
    Solution1 s;

    std::cout << s.divide(10, 3) << std::endl;
    std::cout << s.divide(5, 2) << std::endl;
    std::cout << s.divide(INT_MIN, -1) << std::endl;

    return 0;
}
