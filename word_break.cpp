// #139 Word Break
//
// Given a string s and a dictionary of words dict, determine if s can be
// segmented into a space-separated sequence of one or more dictionary words.
//
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
//
// Return true because "leetcode" can be segmented as "leet code".


#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>

class Solution {

  public:
    bool wordBreak(const std::string&                     s,
                   const std::unordered_set<std::string>& dict)
    {
        // opt(i) = || (opt[k] && s[k, i] is in dict), where k = 0 -> i

        // Add one more element to the opt array to handle the emtpy strings
        // more easily.

        std::vector<bool> opt(s.size() + 1, false);

        opt[0] = true; // empty string is considered as a word

        for (int i = 0; i < s.size(); ++i) {
            bool flag = false;
            for (int k = 0; k <= i; ++k) {
                if (opt[k] && 1 == dict.count(s.substr(k, i - k + 1))) {
                    flag = true;
                    break;
                }
            }
            opt[i + 1] = flag;
        }
        return opt[s.size()];
    }
};

using namespace std;

class Solution {

  public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        int m = s.size();
        if (0 == m) return true;
        vector<bool> opt(m + 1, true);
        for (int i = 1; i <= m; ++i) {
            for (int k = 1; k <= i; ++k) {
                opt[i] = opt[k - 1] && wordDict.count(s.substr(k - 1, i - k + 1));
                if (opt[i]) break;
            }
        }
        return opt[m];
    }
};

int main()
{
    Solution s;
    {
        std::unordered_set<std::string> dict;
        dict.insert("dog");
        dict.insert("s");
        dict.insert("gs");
        std::cout << s.wordBreak("dogs", dict) << std::endl;
    }
    {
        std::unordered_set<std::string> dict;
        dict.insert("dog");
        dict.insert("s");
        dict.insert("gs");
        std::cout << s.wordBreak("dogs", dict) << std::endl;
    }
    return 0;
}
