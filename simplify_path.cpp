// #71 Simplify Path
//
// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
//
// path = "/home/", => "/home"
//
// path = "/a/./b/../../c/", => "/c"
//
// Corner Cases:
//
// Did you consider the case where path = "/../"?
//
// In this case, you should return "/".
//
// Another corner case is the path might contain multiple slashes '/' together,
// such as "/home//foo/".
//
// In this case, you should ignore redundant slashes and return "/home/foo".


#include <iostream>
#include <string>
#include <stack>

class Solution {

  public:
    std::string simplifyPath(const std::string& path)
    {
        std::string             result;
        std::stack<std::string> stack;

        // Tokenize the path and push the tokens onto the stack.

        int start = 0;
        for (int end = 0; end < path.size(); ++end) {
            // Split the path by '/' and get the next token.

            while ('/' != path[end] && end < path.size()) {
                ++end;
            }
            std::string token(path.substr(start, end - start));

            if (token.empty() || "." == token) {
                // If the token is an empty string or ".", just skip it.
                start = end + 1;
                continue;
            } else if (".." == token) {
                // If the token is "..", pop the token from the stack.
                if (!stack.empty()) {
                    stack.pop();
                }
            } else {
                // Otherwise, push the token onto the stack.
                stack.push(token);
            }
            start = end + 1;
        }

        // Reconstruct the path from the tokens in the stack.

        if (stack.empty()) {
            result.push_back('/');
        }
        while (!stack.empty()) {
            result = ('/' + stack.top()) + result;
            stack.pop();
        }

        return result;
    }
};

int main()
{
    Solution s;

    std::cout << s.simplifyPath("/home/") << std::endl;
    std::cout << s.simplifyPath("/a/./b/../../c/") << std::endl;
    std::cout << s.simplifyPath("/../") << std::endl;
    std::cout << s.simplifyPath("/home//foo/") << std::endl;

    return 0;
}
