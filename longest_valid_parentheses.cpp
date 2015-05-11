// #32 Longest Valid Parentheses
//
// Given a string containing just the characters '(' and ')', find the length
// of the longest valid (well-formed) parentheses substring.
//
// For "(()", the longest valid parentheses substring is "()", which has length
// = 2.
//
// Another example is ")()())", where the longest valid parentheses substring
// is "()()", which has length = 4.


#include <string>
#include <vector>
#include <stack>
#include <iostream>

class Solution {
  public:
    int longestValidParentheses(const std::string& s)
    {
        int maximum = 0;
        std::stack<int> stack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && !stack.empty() && s[stack.top()] == '(') {
                // This is a match so we can eliminate this pair.

                stack.pop();
                if (stack.empty()) {
                    // All the preceding parentheses are eliminated.

                    maximum = i + 1;
                } else {
                    maximum = std::max(maximum, i - stack.top());
                }
            } else {
                stack.push(i);
            }
        }
        return maximum;
    }
};

int main()
{
    Solution s;
    std::cout << s.longestValidParentheses("") << std::endl;
    std::cout << s.longestValidParentheses(")") << std::endl;
    std::cout << s.longestValidParentheses("(") << std::endl;
    std::cout << s.longestValidParentheses("(()") << std::endl;
    std::cout << s.longestValidParentheses(")()())") << std::endl;
    std::cout << s.longestValidParentheses("(()()))()") << std::endl;

    return 0;
}
