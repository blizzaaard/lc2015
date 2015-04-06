// #50 Pow(x, n)
//
// Implement pow(x, n).


#include <iostream>

class Solution {

    double helper(double x, int n)
    {
        if (n == 0) {
            return 1;
        }
        double temp = helper(x, n / 2);
        temp *= temp;
        if (1 == n % 2) {
            temp *= x;
        }
        return temp;
    }

  public:
    double pow(double x, int n)
    {
        if (n < 0) {
            return 1 / helper(x, -n);
        } else {
            return helper(x, n);
        }
    }
};

int main()
{
    Solution s;
    std::cout << s.pow(4.5, 5) << std::endl;
    std::cout << s.pow(10, 5) << std::endl;
    return 0;
}
