// #76 Minimum Window Substring
//
// Given a string S and a string T, find the minimum window in S which will
// contain all the characters in T in complexity O(n).
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
//
// Note:
// If there is no such window in S that covers all characters in T, return the
// emtpy string "".
//
// If there are multiple such windows, you are guaranteed that there will
// always be only one unique minimum window in S.


#include <string>
#include <unordered_map>
#include <iostream>

class Solution {
    typedef std::unordered_map<char, int> Hash;

    bool isSatisfied(const Hash& hash)
    {
        for (Hash::const_iterator it = hash.begin(); it != hash.end(); ++it) {
            if (it->second > 0) {
                return false;
            }
        }
        return true;
    }

  public:
    std::string minWindow(const std::string& S, const std::string& T) {
        // The key of the hash map is a character, and the value is the number
        // of occurrence of the character that's not covered by the current
        // window.  A negative value means that the window contains "extra"
        // occurrence of the charactor.

        Hash hash;

        // Populate the hash map with the number of occurrence of the
        // charactors in T when the window is empty on initialization.

        for (int i = 0; i < T.size(); ++i) {
            std::pair<Hash::iterator, bool> ret =
                                        hash.insert(std::make_pair(T[i], 1));
            if (!ret.second) {
                ++ret.first->second;
            }
        }

        int resLeft    = 0;
        int resRight   = 0;
        int resMinimum = S.size();

        int left  = 0;
        int right = 0;

        // We adjust the window in each iteration as follows:
        //
        //   1. Move the right side to right to expand the window, and
        //      decrement the count needed if the newly included charactor is
        //      in S.
        //   2. If the current window satisfies the requirement, move the left
        //      side to the right to shrink the window, and increment the count
        //      needed if the newly excluded charactor is not necessarily in
        //      the window, or stop shrinking otherwise.

        bool isSatisfiedCache = false;
        while (right < S.size()) {
            Hash::iterator it = hash.find(S[right]);
            if (hash.end() != it) {
                // Decrement the count needed since we are expanding the
                // window.

                --it->second;

                // Since we are calling isSatisfied(hash) in the loop the time
                // complexity should be O(ST);

                if (isSatisfiedCache || isSatisfied(hash)) {
                    isSatisfiedCache = true;
                    while (left < right) {
                        Hash::iterator jt = hash.find(S[left]);
                        if (hash.end() != jt) {
                            if (jt->second > -1) {
                                // Not able to shrinking the window since
                                // continuing to do so would exclude necessary
                                // charactor.

                                break;
                            }
                            // Increment the count needed since we are
                            // shrinking the window.

                            ++jt->second;
                        }
                        ++left;
                    }
                    if (resMinimum > right - left) {
                        resMinimum = right - left;
                        resLeft    = left;
                        resRight   = right;
                    }
                }
            }
            ++right;
        }
        return isSatisfiedCache ? S.substr(resLeft, resRight - resLeft + 1)
                                : "";
    }
};
using namespace std;
class Solution1 {
public:
    string minWindow(string S, string T) {
        typedef unordered_map<char, int> Hash;
        string result;
        int start = 0, minLen = INT_MAX;
        Hash dict, tmp;
        for (int i = 0; i < T.size(); ++i) {
            pair<Hash::iterator, bool> ret = dict.insert(make_pair(T[i], 1));
            if (!ret.second) ++ret.first->second;
        }
        int numSatisfied = 0;
        for (int end = 0; end < S.size(); ++end) {
            Hash::iterator it = dict.find(S[end]);
            if (dict.end() == it) continue;
            pair<Hash::iterator, bool> ret = tmp.insert(make_pair(S[end], 1));
            if (!ret.second) ++ret.first->second;
            std::cout << it->second << std::endl;
            std::cout << ret.first->second << std::endl;
            if (ret.first->second == it->second) ++numSatisfied;
            if (numSatisfied < dict.size()) {
                continue;
            }
            while (start <= end) {
                Hash::iterator it = dict.find(S[start]);
                if (dict.end() == it) {
                    ++start;
                    continue;
                }
                Hash::iterator jt = tmp.find(S[start]);
                if (jt->second > it->second) {
                    ++start;
                    --jt->second;
                } else {
                    break;
                }
            }
            if (minLen > end - start + 1) {
                minLen = end - start + 1;
                result = S.substr(start, minLen);
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    std::cout << s.minWindow("aa", "aa") << std::endl;
//    std::cout << s.minWindow("a", "a") << std::endl;
//    std::cout << s.minWindow("bba", "ab") << std::endl;
//    std::cout << s.minWindow("ab", "b") << std::endl;
//    std::cout << s.minWindow("a", "a") << std::endl;
//    std::cout << s.minWindow("ADOBECODEBANC", "ABC") << std::endl;
//    std::cout << s.minWindow("bdab", "ab") << std::endl;
    return 0;
}
