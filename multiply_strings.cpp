// #43 Multiply Strings
//
// Given two numbers represented as strings, return multiplication of the
// numbers as a string.
//
// Note: The numbers can be arbitrarily large and are non-negative.


#include <iostream>
#include <string>
#include <vector>

class Solution {

  public:
    std::string multiply(std::string num1, std::string num2)
    {
        std::string      result;
        std::vector<int> numbers(num1.size() + num2.size(), 0);

        // Do the multiplication and store the result in the 'numbers'.

        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                int k = numbers.size() - i - j - 2;
                numbers[k] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        // Do the addition for the values in the 'numbers'.

        int carry = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            numbers[i] += carry;
            carry = numbers[i] / 10;
            numbers[i] %= 10;
        }

        // Remove leading zeros.

        int start = numbers.size() - 1;
        while (0 < start && numbers[start] == 0) {
            --start;
        }

        // Move the result from a vector into the string.

        for (int i = start; i >= 0; --i) {
           result.push_back(numbers[i] + '0');
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.multiply("123", "123") << std::endl;
    return 0;
}
