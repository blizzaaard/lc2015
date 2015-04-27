// #172 Factorial Trailing Zeroes
//
// Given an integer n, return the number of trailing zeroes in n!.
//
// Note: Your solution should be in logarithmic time complexity.

class Solution {

  public:
    int trailingZeroes(int x)
    {
        int factor = 5, count = 0;
        while (x / factor >= 1) {
            count += x / factor;
            if (INT_MAX / 5 < factor) break;
            factor *= 5;
        }
        return count;
    }
};
