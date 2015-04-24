#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

void print(const vector<string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
}

class Solution {

    enum { LENGTH = 10 };

    /*
    string decode(unsigned int n)
    {
        string result(LENGTH, ' ');
        for (int i = LENGTH - 1; i >= 0; --i) {
            int data = n & 0x11;
            switch (data) {
              case 0: { result[i] = 'A'; } break;
              case 1: { result[i] = 'T'; } break;
              case 2: { result[i] = 'G'; } break;
              case 3: { result[i] = 'C'; } break;
            }
            n >>= 2;
        }
        return result;
    }
    */

    unsigned int encode(const string& s)
    {
        assert(s.size() == LENGTH);
        unsigned int result = 0;
        for (int i = 0; i < LENGTH; ++i) {
            result <<= 2;
            switch (s[i]) {
              case 'A': { result |= 0; } break;
              case 'T': { result |= 1; } break;
              case 'G': { result |= 2; } break;
              case 'C': { result |= 3; } break;
            }
        }
        return result;
    }

  public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> result;
        if (LENGTH >= s.size()) return result;

        typedef unordered_map<unsigned int, int> Hash;
        typedef set<string>                      Set;
        Hash hash;
        Set  set;
        for (int i = 0; i < s.size() - LENGTH + 1; ++i) {
            string sub = s.substr(i, LENGTH);
            pair<Hash::iterator, bool> ret =
                        hash.insert(make_pair(encode(sub), 0));
            ++ret.first->second;
            if (1 < ret.first->second) set.insert(sub);
        }
        for (Set::const_iterator it = set.begin(); it != set.end(); ++it) {
            result.push_back(*it);
        }
        return result;
    }
};

int main()
{
    Solution s;
    print(s.findRepeatedDnaSequences("AAAAAAAAAAA"));
    print(s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"));
    return 0;
}
