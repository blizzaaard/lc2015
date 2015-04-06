// #20 Valid Parentheses
//
// Given a string containing just the characters '(', ')', '{', '}', '[' and
// ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all
// valid but "(]" and "([)]" are not.


#include <iostream>
#include <string>
#include <stack>

class Solution {

  public:
    bool isValid(std::string s)
    {
        std::stack<char> stack;
        for (int i = 0; i < s.size(); ++i) {
            if ('(' == s[i] || '{' == s[i] || '[' == s[i]) {
                stack.push(s[i]);
            } else if (stack.empty()) {
                return false;
            } else if ((')' == s[i] && '(' == stack.top())
                    || ('}' == s[i] && '{' == stack.top())
                    || (']' == s[i] && '[' == stack.top()))
            {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};

int main()
{
    std::string string("()[]{}");
    Solution s;
    std::cout << s.isValid(string) << std::endl;
    return 0;
}
