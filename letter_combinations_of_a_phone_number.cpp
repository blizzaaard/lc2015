// #17 Letter Combinations of a Phone Number
//
// Given a digit string, return all possible letter combinations that the
// number could represent.
//
// A mapping of digit to letters (just like on the telephone buttons) is given
// below.
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// Note:
// Although the above answer is in lexicographical order, your answer could be
// in any order you want.


#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::string>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << std::endl;
    }
}

class Solution_Recursion {

    void helper(std::vector<std::string>        *results,
                std::string                     *result,
                const std::string&               digits,
                const std::vector<std::string>&  letters,
                int                              i)
    {
        if (i >= digits.size()) {
            results->push_back(*result);
            return;
        }
        for (int j = 0; j < letters[digits[i] - '0'].size(); ++j) {
            result->push_back(letters[digits[i] - '0'][j]);
            helper(results, result, digits, letters, i + 1);
            result->pop_back();
        }
    }

  public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        std::vector<std::string> letters(10);
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";

        std::vector<std::string> results;
        if (digits.empty()) {
            results.push_back(digits);
            return results;
        }
        std::string result;
        helper(&results, &result, digits, letters, 0);
        return results;
    }
};

class Solution {

  public:
    std::vector<std::string> letterCombinations(const std::string& digits)
    {
        std::vector<std::string> results;
        results.push_back("");

        std::vector<std::string> letters(10);
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";

        for (int i = 0; i < digits.size(); ++i) {
            int size = results.size();

            // Iterate over each items in the current result and attach
            // each charactor corresponding to digit[i] to the end of it.

            for (int j = 0; j < size; ++j) {
                // Iterate over each charactor corresponding to digit[i].

                for (int k = 0; k < letters[digits[i] - '0'].size(); ++k) {
                    results.push_back(results[j]
                                    + letters[digits[i] - '0'][k]);
                }
            }

            // Remove the old items.

            results.erase(results.begin(), results.begin() + size);
        }

        return results;
    }
};

int main()
{
    Solution s;
    print(s.letterCombinations("23"));

    Solution_Recursion sr;
    print(sr.letterCombinations("23"));

    return 0;
}
