#include <string>
#include <iostream>

/*
class Solution {
  public:
    std::string longestPalindrome(std::string s) {
        int maxLength = 0;
        int maxLeft   = 0;
        int maxRight  = 0;
        for (int i = 0; i < s.size(); ++i) {
            int left   = i - 1;
            int right  = i + 1;
            int length = 0;
            while (0 <= left && right < s.size()) {
                if (s[left] == s[right]) {
                    length += 2;
                    --left;
                    ++right;
                } else {
                    break;
                }
            }
            if (maxLength < length) {
                maxLength = length;
                maxLeft   = left + 1;
                maxRight  = right - 1;
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            int left   = i;
            int right  = i + 1;
            int length = 0;
            while (0 <= left && right < s.size()) {
                if (s[left] == s[right]) {
                    length += 2;
                    --left;
                    ++right;
                } else {
                    break;
                }
            }
            if (maxLength < length) {
                maxLength = length;
                maxLeft   = left + 1;
                maxRight  = right - 1;
            }
        }
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
};
*/

class Solution1 {
public:
    std::string longestPalindrome(std::string s) {
        int maxLength = 0;
        int maxLeft   = 0;
        int maxRight  = 0;
        int flag      = false;
        for (int i = 0; i < s.size(); ) {
            int left   = flag ? i : i - 1;
            int right  = i + 1;
            int length = flag ? 0 : 1;
            while (0 <= left && right < s.size()) {
                if (s[left] == s[right]) {
                    length += 2;
                    --left;
                    ++right;
                } else {
                    break;
                }
            }
            if (maxLength < length) {
                maxLength = length;
                maxLeft   = left + 1;
                maxRight  = right - 1;
            }
            if (flag) {
                ++i;
            }
            flag = !flag;
        }
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    }
};

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int maxLen = 0;
        bool flag = true;
        std::string result;
        for (int i = 0; i < s.size(); ) {
            int k = i, l = i;
            if (!flag) ++l;
            while (k >= 0 && l < s.size()) {
                if (s[k] != s[l]) break;
                if (maxLen < l - k + 1) {
                    maxLen = l - k + 1;
                    result = s.substr(k, l - k + 1);
                }
                --k;
                ++l;
            }
            if (!flag) ++i;
            flag = !flag;
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.longestPalindrome("a") << std::endl;
    std::cout << s.longestPalindrome("abb") << std::endl;
    std::cout << s.longestPalindrome("bb") << std::endl;
    return 0;
}
