// #131 Palindrome Partitioning
//
// Given a string s, partition s such that every substring of the partition is
// a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// For example, given s = "aab",
//
// Return
//
//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]


#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::vector<std::string> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {

    bool isPalindrome(const std::string& s)
    {
        int start = 0;
        int end   = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }

    void helper(std::vector<std::vector<std::string> > *result,
                std::vector<std::string>               *path,
                const std::string&                      s,
                int                                     index)
    {
        if (index == s.size()) {
            result->push_back(*path);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            std::string sub = s.substr(index, i - index + 1);
            if (isPalindrome(sub)) {
                path->push_back(sub);
                helper(result, path, s, i + 1);
                path->pop_back();
            }
        }
    }

  public:
    std::vector<std::vector<std::string> > partition(const std::string& s)
    {
        std::vector<std::vector<std::string> > result;
        std::vector<std::string>               path;
        helper(&result, &path, s, 0);
        return result;
    }
};

int main()
{
    Solution s;
    print(s.partition("aab"));
    return 0;
}
