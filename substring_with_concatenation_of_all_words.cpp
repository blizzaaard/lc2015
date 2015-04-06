// #30 Substring with Concatenation of All Words
//
// You are given a string, S, and a list of words, L, that are all of the same
// length. Find all starting indices of substring(s) in S that is a
// concatenation of each word in L exactly once and without any intervening
// characters.
//
// For example, given:
// S: "barfoothefoobarman"
// L: ["foo", "bar"]
//
// You should return the indices: [0,9].  (order does not matter).


#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
  public:
    std::vector<int> findSubstring(const std::string&              S,
                                   const std::vector<std::string>& L)
    {
        std::vector<int> indices;
        if (L.empty()) {
            return indices;
        }
        int wordLength = L[0].size();
        int numWords   = L.size();
        int windowSize = wordLength * numWords;

        // Construct the dictionary.

        typedef std::unordered_map<std::string, int> Hash;
        Hash golden;
        for (std::vector<std::string>::const_iterator it  = L.begin();
                                                      it != L.end();
                                                    ++it)
        {
            std::pair<Hash::iterator, bool> ret = golden.insert(
                                                    std::make_pair(*it, 1));
            if (!ret.second) {
                ++ret.first->second;
            }
        }

        // Iterater the words in the window and check if every word is in the
        // dictionary.

        for (int i = 0; i < (int) S.size() - windowSize + 1; ++i) {
            std::unordered_map<std::string, int> hash = golden;
            int flag = true;
            for (int j = 0; j < numWords; ++j) {
                std::string str = S.substr(i + wordLength * j, wordLength);
                std::unordered_map<std::string, int>::iterator it =
                                                                hash.find(str);
                if (hash.end() != it && it->second > 0) {
                    --it->second;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                indices.push_back(i);
            }
        }
        return indices;
    }
};

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> L(2);
    L[0] = "foo";
    L[1] = "bar";
    Solution s;
    print(s.findSubstring("barfoothefoobarman", L));

    return 0;
}
