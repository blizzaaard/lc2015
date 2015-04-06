// #128 Longest Consecutive Sequence
//
// Given an unsorted array of integers, find the length of the longest
// consecutive elements sequence.
//
// For example,
//
// Given [100, 4, 200, 1, 3, 2],
//
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its
// length: 4.
//
// Your algorithm should run in O(n) complexity.


#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {

  public:
    int longestConsecutive(std::vector<int>& num)
    {
        int maxLength = 0;

        std::unordered_set<int> hash;
        for (int i = 0; i < num.size(); ++i) {
            hash.insert(num[i]);
        }

        for (int i = 0; i < num.size(); ++i) {
            int length = 0;
            for (int n = num[i]; ; --n) {
                std::unordered_set<int>::iterator it = hash.find(n);
                if (hash.end() == it) {
                    break;
                }
                ++length;
                hash.erase(it);
            }
            for (int n = num[i] + 1; ; ++n) {
                std::unordered_set<int>::iterator it = hash.find(n);
                if (hash.end() == it) {
                    break;
                }
                ++length;
                hash.erase(it);
            }
            maxLength = std::max(maxLength, length);
        }
        return maxLength;
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> num;
        num.push_back(0);
        std::cout << s.longestConsecutive(num) << std::endl;
    }
    return 0;
}
