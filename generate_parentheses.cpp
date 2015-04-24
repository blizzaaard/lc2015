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

using namespace std;

void print(const vector<string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    cout << endl;
}

class Solution {

    void helper(vector<string> *result, const string& path,
                int l, int r, int n)
    {
        if (l == n && r == n) {
            result->push_back(path);
            return;
        }
        // Not possible to match since we have more ')' than '(' so far.
        if (l < r) return;
        if (l < n) helper(result, path + '(', l + 1, r, n);
        if (r < n) helper(result, path + ')', l, r + 1, n);
    }

  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        helper(&result, "", 0, 0, n);
        return result;
    }
};

int main()
{
    Solution s;
    print(s.generateParenthesis(0));
    print(s.generateParenthesis(5));
    return 0;
}
