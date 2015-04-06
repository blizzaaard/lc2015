// #38 Count and Say
//
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.

#include <string>
#include <iostream>
#include <sstream>

class Solution {
  public:
    std::string countAndSay(int n) {
        std::string number("1");
        for (int i = 0; i < n - 1; ++i) {
            std::string nextNumber;
            int count = 1;

            for (int j = 1; j < number.size(); ++j) {
                if (number[j] == number[j - 1]) {
                    ++count;
                } else {
                    std::ostringstream oss;
                    oss << count;
                    nextNumber += oss.str();
                    nextNumber += number[j - 1];
                    count = 1;
                }
            }

            // Process the remaining part

            if (!number.empty()) {
                std::ostringstream oss;
                oss << count;
                nextNumber += oss.str();
                nextNumber += number[number.size() - 1];
            }
            nextNumber.swap(number);
        }
        return number;
    }
};

int main()
{
    Solution s;
    std::cout << s.countAndSay(5) << std::endl;
    return 0;
}
