// #127 Word Ladder
//
// Given two words (start and end), and a dictionary, find the length of
// shortest transformation sequence from start to end, such that:
//
// 1. Only one letter can be changed at a time
// 2. Each intermediate word must exist in the dictionary
//
// For example,
//
// Given:
//
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]
//
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Note:
//  - Return 0 if there is no such transformation sequence.
//  - All words have the same length.
//  - All words contain only lowercase alphabetic characters.


#include <string>
#include <unordered_set>
#include <iostream>
#include <queue>

class Solution {

  public:
    int ladderLength(const std::string&                     start,
                     const std::string&                     end,
                     const std::unordered_set<std::string>& dict)
    {
        // We use BFS to traverse the space.

        if (start == end) {
            return 1;
        }
        int depth = 2;
        std::queue<std::string>         queue;
        std::unordered_set<std::string> visited;
        queue.push(start);
        visited.insert(start);
        int numCurr = 1; // number of nodes at the current level
        int numNext = 0; // number of children nodes at the next level
        while (!queue.empty()) {
            std::string word = queue.front();
            queue.pop();
            --numCurr;
            for (int i = 0; i < word.size(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (word[i] != c) {
                        std::string next = word;
                        next[i] = c;
                        if (next == end) {
                            return depth;
                        }
                        // check if the node is in the dictionary and not
                        // visited.
                        if (1 == dict.count(next) && 0 == visited.count(next))
                        {
                            queue.push(next);
                            visited.insert(next);
                            ++numNext;
                        }
                    }
                }
            }
            if (0 == numCurr) {
                // we have visited all the nodes at the current level, and we
                // will start visiting the nodes at the next level.
                numCurr = numNext;
                numNext = 0;
                ++depth;
            }
        }
        return 0;
    }
};

int main()
{
    std::unordered_set<std::string> dict;
    dict.insert("a");
    dict.insert("b");
    dict.insert("c");

    Solution s;
    std::cout << s.ladderLength("a", "c", dict) << std::endl;
    return 0;
}
