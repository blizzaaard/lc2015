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

using namespace std;

class Solution {

  public:
    int climbStairs(int n)
    {
        vector<int> opt(2, 0);
        opt[0] = 1;
        opt[1] = 2;
        if (n < 2) return opt[n - 1];
        for (int i = 2; i < n; ++i) {
            int newStep = opt[0] + opt[1];
            opt[0] = opt[1];
            opt[1] = newStep;
        }
        return opt[1];
    }
};

int main()
{
    Solution s;
    std::cout << s.climbStairs(5) << std::endl;
    return 0;
}
