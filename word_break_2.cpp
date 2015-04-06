// #140 Word Break II
//
// Given a string s and a dictionary of words dict, add spaces in s to
// construct a sentence where each word is a valid dictionary word.
//
// Return all such possible sentences.
//
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
//
// A solution is ["cats and dog", "cat sand dog"].


#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void print(const std::vector<std::string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    std::cout << std::endl;
}

class Solution {

    std::unordered_map<int, bool> cache;
        // A cache for the recursive call.  If s[index, end) has already been
        // visited and it cannot be divided into words, we don't need to
        // revisit it again.  However, if s[index, end) has been visited but it
        // can be divided into words, we need to visit it again in order to
        // dump all the solutions.

    bool helper(std::vector<std::string>               *result,
                std::string                            *segments,
                const int                               index,
                const std::string&                      s,
                const std::unordered_set<std::string>&  dict)
    {
        if (cache.count(index) && !cache[index]) {
            // If we already know that s[index, end) cannot be divided into
            // words, we don't need to recalculate again.

            return false;
        }

        if (index == s.size()) {
            result->push_back(*segments);
            return true;
        }

        int flag = false;
        for (int i = index; i < s.size(); ++i) {
            const std::string word = s.substr(index, i - index + 1);
            if (1 == dict.count(word)) {
                int length = segments->size();

                if (!segments->empty()) {
                    // Do not need to add a space for the first word

                    (*segments) += " ";
                }

                (*segments) += word;      // add the word to the string
                flag |= helper(result, segments, i + 1, s, dict);
                segments->resize(length); // remove the word from the string
            }
        }
        cache[index] = flag;

        return flag;
    }

  public:
    const std::vector<std::string> wordBreak(
            const std::string&                     s,
            const std::unordered_set<std::string>& dict)
    {
        std::vector<std::string> result;
        std::string              segments;
        helper(&result, &segments, 0, s, dict);
        return result;
    }
};

int main()
{
    Solution s;
    {
        std::unordered_set<std::string> dict;
        dict.insert("cat");
        dict.insert("cats");
        dict.insert("and");
        dict.insert("sand");
        dict.insert("dog");
        print(s.wordBreak("catsanddog", dict));
    }
    {
        std::unordered_set<std::string> dict;
        dict.insert("dog");
        dict.insert("s");
        dict.insert("gs");
        print(s.wordBreak("dogs", dict));
    }
    {
        std::unordered_set<std::string> dict;
        dict.insert("a");
        dict.insert("aa");
        dict.insert("aaa");
        dict.insert("aaaa");
        dict.insert("aaaaa");
        dict.insert("aaaaaa");
        dict.insert("aaaaaaa");
        dict.insert("aaaaaaaa");
        dict.insert("aaaaaaaaa");
        dict.insert("aaaaaaaaaa");
        s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", dict);
    }
    return 0;
}
