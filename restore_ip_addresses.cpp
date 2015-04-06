// #93 Restore IP Addresses
//
// Given a string containing only digits, restore it by returning all possible
// valid IP address combinations.
//
// For example:
// Given "25525511135",
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution {

    enum {
        NUM_SEGMENTS = 4,
        MAX_DIGITS   = 3
    };

    bool isValid(const std::string& s, int i, int j)
        // Return 'true' if s[i, j] is a valid part of IP address, and 'false'
        // otherwise.
    {
        int size = j - i + 1;
        if (1 == size) {
            // Single digit [0, 9] is always valid.
            return true;
        } else if (2 == size) {
            // Double digits [10, 99] is valid unless the first digit is not
            // zero.
            return s[i] != '0';
        } else if (3 == size) {
            // Triple digits is valid when it's in [100-255].
            std::istringstream iss(s.substr(i, size));
            int temp = -1;
            iss >> temp;
            return (100 <= temp && temp <= 255) ? true : false;
        } else {
            return false;
        }
    }
    void helper(std::vector<std::string> *result,
                std::vector<std::string> *ip,
                const std::string&        s,
                int                       index)
    {
        if (index == s.size()) {
            if (NUM_SEGMENTS == ip->size()) {
                std::string temp(ip->front());
                for (int i = 1; i < ip->size(); ++i) {
                    temp += '.';
                    temp += (*ip)[i];
                }
                result->push_back(temp);
            }
            return;
        }
        for (int i = index; i - index < MAX_DIGITS && i < s.size(); ++i) {
            if (s.size() - i - 1 < NUM_SEGMENTS - 1 - ip->size()) {
                // We don't have enough digits left to form a valid IP address.
                return;
            }
            if (isValid(s, index, i)) {
                ip->push_back(s.substr(index, i - index + 1));
                helper(result, ip, s, i + 1);
                ip->pop_back();
            }
        }
    }

  public:
    std::vector<std::string> restoreIpAddresses(const std::string& s)
    {
        std::vector<std::string> result;
        std::vector<std::string> ip;
        helper(&result, &ip, s, 0);
        return result;
    }
};

void print(const std::vector<std::string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    Solution s;
    print(s.restoreIpAddresses("25525511135"));
    print(s.restoreIpAddresses("20000"));
    print(s.restoreIpAddresses("0000"));
    return 0;
}
