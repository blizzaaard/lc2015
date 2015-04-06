// #22 Generate Parentheses
//
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// For example, given n = 3, a solution set is:
//
// "((()))", "(()())", "(())()", "()(())", "()()()"


#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
    std::cout << std::endl;
}

class Solution {

    void helper(std::vector<std::string> *results,
                const std::string&        result,
                int                       left,
                int                       right,
                int                       n)
    {
        if (left < right) {
            // Not possible to match since we have more ')' than '(' so far.
            return;
        }
        if (left == n && right == n) {
            results->push_back(result);
            return;
        }
        if (left < n) {
            helper(results, result + '(', left + 1, right, n);
        }
        if (right < n) {
            helper(results, result + ')', left, right + 1, n);
        }
    }

  public:
    std::vector<std::string> generateParentheses(int n)
    {
        std::vector<std::string> results;
        helper(&results, "", 0, 0, n);
        return results;
    }
};

int main()
{
    Solution s;
    print(s.generateParentheses(0));
    print(s.generateParentheses(5));
    return 0;
}
