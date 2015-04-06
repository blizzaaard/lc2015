// #69 Sqrt(x)
//
// Implement int sqrt(int x).
//
// Compute and return the square root of x.


#include <cmath>
#include <iostream>

class Solution {

  public:
    int sqrt(int a)
    {
        if (0 == a) {
            return 0;
        }

        //           f(x0)    x0^2 + a
        // x0 - x1 = ------ = --------
        //           f'(x0)      2x0

        double x0 = 0;
        double x1 = a;
        do {
            x0 = x1;
            x1 = (x0 + a / x0) / 2;
        } while (std::abs(x1 - x0) > 0.0000001);

        return x1;
    }
};

int main()
{
    Solution s;
    std::cout << s.sqrt(2) << std::endl;
    return 0;
}
