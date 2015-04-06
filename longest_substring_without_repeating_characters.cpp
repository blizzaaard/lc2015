// #3 Longest Substring Without Repeating Characters
//
// Given a string, find the length of the longest substring without repeating
// characters. For example, the longest substring without repeating letters for
// "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest
// substring is "b", with the length of 1.


#include <iostream>
#include <string>
#include <unordered_set>

class Solution {

  public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        std::unordered_set<int> hash;
        int left    = 0;
        int right   = 0;
        int maximum = 0;
        for (right = 0; right < s.size(); ++right) {
            if (0 == hash.count(s[right])) {
                // s[right] is not a repeating character.

                hash.insert(s[right]);
            } else {
                // s[right] is a repeating character, so we need to caculate
                // the max length and then shrink the window.

                // TODO: no need to update the maximum length when shrinking
                // the window.
                maximum = std::max(maximum, right - left);

                while (s[left] != s[right]) {
                    hash.erase(s[left]);
                    ++left;
                }

                // This is for s[left] == s[right], so that we don't need to
                // remove the charactor from the hash map and then add the same
                // charactor to the hash map again.

                ++left;
            }
        }
        maximum = std::max(maximum, right - left);
        return maximum;
    }
};

int main()
{
    {
        std::string str("eee");
        Solution s;
        std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    }
    {
        std::string str("qopubjguxhxdipfzwswybgfylqvjzhar");
        Solution s;
        std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    }

    {
        std::string str("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco");
        Solution s;
        std::cout << s.lengthOfLongestSubstring(str) << std::endl;
    }
    return 0;
}
