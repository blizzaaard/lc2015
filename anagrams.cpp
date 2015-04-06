// #49 Anagrams
//
// Given an array of strings, return all groups of strings that are anagrams.
//
// Note: All inputs will be in lower-case.


#include <iostream>
#include <unordered_map>
#include <vector>

void print(const std::vector<std::string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    std::cout << std::endl;
}

class Solution {

  public:
    std::vector<std::string> anagrams(const std::vector<std::string>& strs)
    {
        typedef std::unordered_map<std::string, std::vector<std::string> >
                Hash;
        Hash hash;

        std::vector<std::string> result;
        for (std::vector<std::string>::const_iterator it  = strs.begin();
                                                      it != strs.end();
                                                    ++it)
        {
            std::string sorted(*it);
            std::sort(sorted.begin(), sorted.end());

            std::pair<Hash::iterator, int> ret = hash.insert(
                        std::make_pair(sorted, std::vector<std::string>()));
            ret.first->second.push_back(*it);
        }

        for (Hash::const_iterator it  = hash.begin();
                                  it != hash.end();
                                ++it)
        {
            if (1 < it->second.size()) {
                result.insert(result.begin(),
                              it->second.begin(),
                              it->second.end());
            }
        }
        return result;
    }
};

int main()
{
    Solution s;

    std::vector<std::string> strs;
    strs.push_back("abc");
    strs.push_back("bac");
    strs.push_back("acb");
    strs.push_back("adb");
    print(s.anagrams(strs));

    return 0;
}
