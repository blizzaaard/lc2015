
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        unsigned int unumerator = numerator > 0 ? numerator : -numerator;
        unsigned int udenominator = denominator > 0 ? denominator : -denominator;

        string result;

        if (0 != unumerator) {
            if ((numerator > 0 && denominator < 0)
            ||  (numerator < 0 && denominator > 0))
            {
                result += '-';
            }
        }

        if (unumerator > udenominator) {
            ostringstream oss;
            oss << unumerator / udenominator;
            result += oss.str();
        } else {
            result += '0';
        }
        if (unumerator % udenominator) result += '.';

        unordered_map<int, int> map;
        bool loop = false;
        string digits;
        long long remainder = (unumerator % udenominator) * 10;

        while (remainder) {
            if (map.find(remainder) != map.end()) {
                loop = true;
                break;
            }
            map.insert(make_pair(remainder, digits.size()));
            digits += (remainder / udenominator) + '0';
            remainder = remainder % udenominator;
            remainder *= 10;
        }
        if (loop) {
            digits.insert(map[remainder], 1, '(');
            digits += ')';
        }
        result += digits;
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.fractionToDecimal(1, 2147483648) << endl;
    cout << s.fractionToDecimal(1, 99) << endl;
    cout << s.fractionToDecimal(INT_MIN, 1) << endl;
    cout << s.fractionToDecimal(INT_MIN, -1) << endl;
    cout << s.fractionToDecimal(1, 6) << endl;
    cout << s.fractionToDecimal(1, 3) << endl;
    cout << s.fractionToDecimal(2, 3) << endl;
    cout << s.fractionToDecimal(1, 199) << endl;
    return 0;
}
