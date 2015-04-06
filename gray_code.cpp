// #89 Gray Code
//
// The gray code is a binary numeral system where two successive values differ
// in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the
// code, print the sequence of gray code. A gray code sequence must begin with
// 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
// Note:
//
// For a given n, a gray code sequence is not uniquely defined.
//
// For example, [0,2,3,1] is also a valid gray code sequence according to the
// above definition.


#include <vector>
#include <iostream>
#include <bitset>

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> result(1, 0);
        if (0 == n) {
            return result;
        }

        // ----
        //   00
        //   01
        //   11
        //   10
        // ----
        //
        //  TO
        //
        // ----
        // 0 00
        // 0 01
        // 0 11
        // 0 10
        //
        // 1 10  reverse order + 1 at the most significant bit
        // 1 00
        // 1 01
        // 1 11
        // ----

        for (int i = 1; i <= n; ++i) {
            for (int j = result.size() - 1; j >= 0; --j) { // reverse order
                result.push_back(result[j] + (1 << (i - 1)));
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    print(s.grayCode(2));
    print(s.grayCode(3));

    return 0;
}
