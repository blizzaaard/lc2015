// #205 Isomorphic Strings
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character but a character may map to itself.
//
// For example,
//
// Given "egg", "add", return true.
//
// Given "foo", "bar", return false.
//
// Given "paper", "title", return true.
//
// Note:
// You may assume both s and t have the same length.


#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

  public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, char>::const_iterator it = map1.find(s[i]);
            if (map1.end() == it) map1.insert(make_pair(s[i], t[i]));
            else if (it->second != t[i]) return false;
            it = map2.find(t[i]);
            if (map2.end() == it) map2.insert(make_pair(t[i], s[i]));
            else if (it->second != s[i]) return false;
        }
        return true;
    }
};
