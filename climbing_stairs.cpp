// #70 Climbing Stairs
//
// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?


#include <iostream>

class Solution {

  public:
    int climbStairs(int n)
    {
        if (n < 2) {
            return n;
        }

        int a = 1; // opt[i - 1]
        int b = 2; // opt[i]

        // opt[i] = opt[i - 1] + opt[i - 2]

        for (int i = 2; i < n; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};

int main()
{
    Solution s;
    std::cout << s.climbStairs(5) << std::endl;
    return 0;
}
