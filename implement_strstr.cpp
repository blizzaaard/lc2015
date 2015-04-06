// #28 Implement strStr()
//
// Implement strStr().
//
// Returns the index of the first occurrence of needle in haystack, or -1 if
// needle is not part of haystack.


#include <iostream>

class Solution {

  public:
    int strStr(const char* haystack, const char *needle)
    {
        if (!*needle) {
            return 0;
        }

        const char *end = haystack;
        const char *p2  = needle;

        // Find the last charactor in 'haystack' that needs to be tested.  This
        // is an optimization.

        while (*p2++) {
            if (!*end++) {
                return -1; // not found
            }
        }
        --end;

        const char *pstart = haystack;
            // The start position in 'haystack'.

        while (*end++) {
            const char *p1 = pstart;
            const char *p2 = needle;
            while (*p1 && *p2 && *p1 == *p2) {
                ++p1;
                ++p2;
            }
            if (!*p2) {
                return pstart - haystack;
            }
            ++pstart;
        }

        return -1;
    }
};

int main()
{
    Solution s;

    std::cout << s.strStr("This is simple", "simple") << std::endl;
    std::cout << s.strStr("This is simpler", "simple") << std::endl;
    std::cout << s.strStr("simpl", "simple") << std::endl;
    std::cout << s.strStr("simple", "simple") << std::endl;
    std::cout << s.strStr("", "simple") << std::endl;
    std::cout << s.strStr("simple", "") << std::endl;
    std::cout << s.strStr("", "") << std::endl;
    std::cout << s.strStr("123", "23") << std::endl;

    return 0;
}
