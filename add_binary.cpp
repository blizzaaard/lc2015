// #67 Add Binary
//
// Given two binary strings, return their sum (also a binary string).
//
// For example,
// a = "11"
// b = "1"
// Return "100".


#include <iostream>
#include <vector>

class Solution {
  public:
    std::string addBinary(const std::string& a, const std::string& b)
    {
        int carry = 0;
        int m     = a.size();
        int n     = b.size();

        std::string result(std::max(m, n) + 1, 0);

        for (int i = m - 1, j = n - 1, pos = result.size() - 1;
                i >= 0 || j >= 0;)
        {
            int value = carry;
            if (i >= 0) {
                value += a[i] - '0';
                --i;
            }
            if (j >= 0) {
                value += b[j] - '0';
                --j;
            }
            carry = value / 2;
            value = value % 2;
            result[pos--] = value + '0';
        }
        if (carry) {
            result[0] = carry + '0';
        } else if (0 == result[0]) {
            return result.substr(1);
        }
        return result;
    }
};

int main()
{
    Solution s;

    std::cout << s.addBinary("", "") << std::endl;
    std::cout << s.addBinary("0", "") << std::endl;
    std::cout << s.addBinary("", "0") << std::endl;
    std::cout << s.addBinary("1", "") << std::endl;
    std::cout << s.addBinary("", "1") << std::endl;
    std::cout << s.addBinary("0", "0") << std::endl;
    std::cout << s.addBinary("0", "1") << std::endl;
    std::cout << s.addBinary("1", "0") << std::endl;
    std::cout << s.addBinary("1", "1") << std::endl;
    std::cout << s.addBinary("11", "11") << std::endl;
    std::cout << s.addBinary("11", "1") << std::endl;
    std::cout << s.addBinary("1", "11") << std::endl;
    std::cout << s.addBinary("111111", "1") << std::endl;
    std::cout << s.addBinary("1", "111111") << std::endl;

    return 0;
}
