// #91 Decode Ways
//
// A message containing letters from A-Z is being encoded to numbers using the
// following mapping:
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
// Given an encoded message containing digits, determine the total number of
// ways to decode it.
//
// For example,
//
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
//
// The number of ways decoding "12" is 2.


#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Solution_Recursion {

    void helper(int *count, const std::string& s)
    {
        int size = s.size();
        if (0 == size) {
            return;
        } else if (1 == size) {
            if ('0' != s[0]) {
                ++(*count);
            }
            return;
        } else {
            helper(count, s.substr(1));

            std::istringstream iss(s.substr(0, 2));
            int temp = -1;
            iss >> temp;
            if (0 < temp && temp < 27) {
                helper(count, s.substr(2));
            }
        }
    }

  public:
    int numDecodings(const std::string& s)
    {
        int count = 0;
        helper(&count, s);
        return count;
    }
};

class Solution {

    bool isValid(const std::string& s, int index)
        // Return 'true' if s[index - 1, index] is valid, and 'false'
        // otherwise.
    {
        if (s[index - 1] == '0') {
            return false;
        }
        std::istringstream iss(s.substr(index - 1, 2));
        int temp = -1;
        iss >> temp;
        return (0 < temp && temp < 27) ? true : false;
    }

  public:
    int numDecodings(const std::string& s) {
        // opt(i) = opt(i - 1) + opt(i - 2)
        //
        // To minimize memory usage, we use
        //     opt[2] == opt(i)
        //     opt[1] == opt(i - 1)
        //     opt[0] == opt(i - 2)

        if (s.empty() || s[0] == '0') {
            return 0;
        }
        std::vector<int> opt(3, 1);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                // opt(i - 1) won't be considered since the current position is
                // zero.

                if (!isValid(s, i)) {
                    // e.g. 200
                    //       ^^ (00 is invalid)
                    // e.g. 250
                    //       ^^ (50 is invalid)
                    return 0;
                } else {
                    // opt(i) = opt(i - 2)
                    //
                    // e.g. 220
                    //       ^^ (20 is valid but 0 is invalid)
                    opt[2] = opt[0];
                }
            } else {
                // opt(i - 1) will always be considered.

                if (!isValid(s, i)) {
                    // opt(i) = opt(i - 1)
                    //
                    // e.g. 227
                    //        ^ (7 is valid but 27 is invalid)
                    opt[2] = opt[1];
                } else {
                    // e.g. 226
                    //        ^ (6 is valid)
                    //       ^^ (26 is valid)
                    opt[2] = opt[0] + opt[1];
                }
            }
            opt[0] = opt[1];
            opt[1] = opt[2];
        }
        return opt[2];
    }
};

int main()
{
    Solution s;
    std::cout << s.numDecodings("200") << std::endl;
    std::cout << s.numDecodings("227") << std::endl;
    std::cout << s.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948")
              << std::endl;

    Solution_Recursion sr;
    std::cout << sr.numDecodings("200") << std::endl;
    std::cout << sr.numDecodings("227") << std::endl;
    std::cout << sr.numDecodings("4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948")
              << std::endl;

    return 0;
}
