// #66 Plus One
//
// Given a non-negative number represented as an array of digits, plus one to
// the number.
//
// The digits are stored such that the most significant digit is at the head of
// the list.


#include <iostream>
#include <vector>

class Solution {
  public:
    /* This is uncessarily complicated
     *
    vector<int> plusOne_1(vector<int> &digits) {
        std::vector<int> result;
        if (digits.empty()) {
            return result;
        }
        int n = digits.size() - 1;
        int sum = digits[n] + 1;
        int flag = sum / 10;
        result.push_back(sum % 10);
        for (int i = n - 1; i >= 0; --i) {
            sum = digits[i] + flag;
            flag = sum / 10;
            result.push_back(sum % 10);
        }
        if (1 == flag) {
            result.push_back(1);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
    */

    std::vector<int> plusOne(std::vector<int>& digits)
    {
        std::vector<int> result = digits;

        int i = result.size() - 1;
        for (; i >= 0; --i) {
            if (result[i] != 9) {
                ++result[i];
                return result;
            } else {
                result[i] = 0;
            }
        }
        if (-1 == i) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};

using namespace std;

class Solution1 {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = false;
        int i = digits.size() - 1;
        for (; i >= 0; --i) {
            if (9 == digits[i]) {
                digits[i] = 0;
                carry = true;
            } else break;
        }
        if (carry && 0 == i) digits.insert(digits.begin(), 1);
        else ++digits[i];
        return digits;
    }
};

int main()
{
    Solution1 s;
    vector<int> digits;
    digits.push_back(0);
    s.plusOne(digits);


    return 0;
}
