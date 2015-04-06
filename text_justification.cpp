// #68 Text Justification
//
// Given an array of words and a length L, format the text such that each line
// has exactly L characters and is fully (left and right) justified.
//
// You should pack your words in a greedy approach; that is, pack as many words
// as you can in each line. Pad extra spaces ' ' when necessary so that each
// line has exactly L characters.
//
// Extra spaces between words should be distributed as evenly as possible. If
// the number of spaces on a line do not divide evenly between words, the empty
// slots on the left will be assigned more spaces than the slots on the right.
//
// For the last line of text, it should be left justified and no extra space is
// inserted between words.
//
// For example,
//
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
//
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.
//
// click to show corner cases.
//
// Corner Cases:
//
// A line other than the last line might contain only one word. What should you
// do in this case?
//
// In this case, that line should be left-justified.


#include <vector>
#include <string>
#include <iostream>

void print(const std::vector<std::string>& lines)
{
    for (int i = 0; i < lines.size(); ++i) {
        std::cout << "|" << lines[i] << "|" << std::endl;
    }
}

class Solution {

    std::string helper(const std::vector<std::string>& words,
                       int                             length,
                       int                             L,
                       bool                            lastLine)
        // words    - words in the line
        // lenght   - length of the words (excluding spaces)
        // L        - lenght of the line
        // lastLine - 'true' if this is the last line
    {
        std::string line;
        int n = words.size();
        if (0 == words[0].size()) {
            return std::string(L, ' ');
        }
        int avgSpaces = 0;
        int k         = 0;
        if (1 == n) {
            avgSpaces = L - length;
            k         = 0;
        } else if (lastLine) {
            avgSpaces = 1;
            k         = 0;
        } else {
            avgSpaces = (L - length) / (n - 1);
            k         = (L - length) % (n - 1);
        }
        for (int i = 0; i < n; ++i) {
            int currSpaces = 1 != n && n - 1 == i
                           ? 0
                           : (i < k ? avgSpaces + 1 : avgSpaces);
            line += words[i] + std::string(currSpaces, ' ');
        }
        line.resize(L, ' ');
        return line;
    }

  public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words,
                                         int                       L)
    {
        std::vector<std::string> result;

        int curr   = 0;
        int total  = words.size();
        int length = 0;

        std::vector<std::string> line;
        while (curr < total) {
            if ((line.empty() && words[curr].size() == L)
            ||  (length + words[curr].size() <= L))
            {
                // Accumulate words into a line.

                line.push_back(words[curr]);
                length += words[curr].size() + 1;
                ++curr;
            } else {
                // Process a single line.

                result.push_back(
                        helper(line, length - line.size(), L, curr == total));
                line.clear();
                length = 0;
            }
        }
        if (!line.empty()) {
            result.push_back(helper(line, length - line.size(), L, true));
        }
        return result;
    }
};

int main()
{
    Solution s;

    {
        std::vector<std::string> words;
        words.push_back("Listen");
        words.push_back("to");
        words.push_back("many");
        words.push_back("speak");
        words.push_back("to");
        words.push_back("a");
        words.push_back("few.");

        print(s.fullJustify(words, 6));
    }

    {
        std::vector<std::string> words;
        words.push_back("");

        print(s.fullJustify(words, 3));
    }

    {
        std::vector<std::string> words;
        words.push_back("This");
        words.push_back("is");
        words.push_back("an");
        words.push_back("example");
        words.push_back("of");
        words.push_back("text");
        words.push_back("justification.");

        print(s.fullJustify(words, 16));
    }

    return 0;
}
