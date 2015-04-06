#include <iostream>
#include <vector>

int mem[1000][1000] = { 0 };

const char *os = 0;
const char *op = 0;

int numCalls = 0;
int indent = -1;

struct IndentGuard {
    IndentGuard()
    {
        ++indent;
    }

    ~IndentGuard()
    {
        --indent;
    }
};

void print(const std::vector<std::vector<int> > v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            std::cout << v[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {
  public:

    // Submission Result: Wrong Answer
    // Input:    "aaa", "ab*a*c*a"
    // Output:   false
    // Expected: true

    // When input is "aa", the regular expression "a*b*a" does not match if
    // using the following algorithm, however, the wildcard expression "**a"
    // does match, because unlike "b*" being unable to replace "a*", two "*"s
    // can replace each other.

    bool isMatch_wrong(const char *s, const char *p) {
        const char *star = 0;
        const char *prev = 0;
        while (*s) {
            if (*p && '*' == *(p + 1)) {
                star = p + 1;
                p = p + 2;
                prev = s;
            } else if ('.' == *p || *s == *p) {
                ++s;
                ++p;
            } else if (star) {
                if ('.' != *(star - 1) && *prev != *(star - 1)) {
                    return false;
                }
                s = prev + 1;
                prev = s;
                p = star + 1;
            } else  {
                return false;
            }
        }
        while (*p && '*' == *(p + 1)) {
            p += 2;
        }
        return !*p;
    }

    bool isMatch_recursive(const char *s, const char *p) {
        if (!*p) {
            return !*s;
        }

        if ('*' != *(p + 1)) {
            return (*s == *p || ('.' == *p && *s)) ? isMatch(s + 1, p + 1) : false;
        } else {
            do {
                if (isMatch(s, p + 2)) {
                    return true;
                }
                ++s;
            } while (*(s - 1) == *p || ('.' == *p && *(s - 1)));
            return false;
        }
    }

    bool isMatch(const char *s, const char *p) {
        if (!*s) {
            return true;
        }
        if (!*p) {
            return false;
        }
        int m = ::strlen(s);
        int n = ::strlen(p);
        std::vector<std::vector<int> > opt;
        opt.resize(m);
        for (int i = 0; i < m; ++i) {
            opt[i].resize(n);
        }

        // every char in s to the last char in p
        const char *last_s = s + m - 1;
        const char *last_p = p + n - 1;
        if ('*' != *last_p) {
            if (*last_s == *last_p || '.' == *last_p) {
                opt[m - 1][n - 1] = 1;
            }
        } else if ('*' == *last_p) {
            --last_p;
            for (int i = m - 1; i >= 0; --i) {
                const char *curr_s = s + i;
                if (*curr_s == *last_p || '.' == *last_p) {
                    opt[i][n - 2] = 1;
                } else {
                    break;
                }
            }
        }

        // the last char in s to every char in p.
        bool flag = false;
        for (int j = n - 1; j >= 0; --j) {
            const char *curr_p = p + j;
            if ('*' == *curr_p) {
                continue;
            }
            if ('*' == *(curr_p + 1)) {
                if (flag || *curr_p == *last_s || '*' == *curr_p) {
                    opt[m - 1][j] = 1;
                }
            } else {
                if (*last_s == *curr_p || '.' == *curr_p) {
                    if (!flag) {
                        opt[m - 1][j] = 1;
                        flag = true;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }
        }

        int j = '*' == *(p + n - 1) ? n - 3 : n - 2;
        for ( ; j >= 0; --j) {
            const char *curr_p = p + j;
            if ('*' == *curr_p) {
                continue;
            }
            for (int i = m - 2; i >= 0; --i) {
                const char *curr_s = s + i;
                if ('*' != *(curr_p + 1)) {
                    opt[i][j] = *curr_s == *curr_p || '.' == *curr_p
                              ? opt[i + 1][j + 1]
                              : false;
                } else {
                    int k = i;
                    do {
                        opt[i][j] += opt[k][j + 2];
                        ++k;
                    } while (k < m && (*(s + k - 1) == *curr_p || '.' == *curr_p));
                }
            }
        }
        return opt[0][0];
    }
};

int main()
{
//    {
//        Solution s;
//        std::cout << s.isMatch("aa", ".*") << std::endl;
//    }
//
//    {
//        Solution s;
//        std::cout << s.isMatch("aaab", "a*a*a*") << std::endl;
//        std::cout << numCalls << std::endl;
//        numCalls = 0;
//    }
    {
        Solution s;
        std::cout << s.isMatch("aaa", "ab*ac*a") << std::endl;
    }
//    { 
//        Solution s;
//        std::cout << s.isMatch("aaa", "aaaa") << std::endl;
//        numCalls = 0;
//    }
//    {
//        Solution s;
//        std::cout << s.isMatch("a", "ab*") << std::endl;
//        numCalls = 0;
//    }

    return 0;
}
