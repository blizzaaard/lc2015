#include <string>
#include <iostream>

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }
        std::string result;
        int size = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
            for (int base = i; base < s.size() ;base += size) {
                result.append(1, s[base]);
                if (0 < i && i < nRows - 1) {
                    int pos = base + size - 2 * i;
                    if (pos < s.size()) {
                        result.append(1, s[pos]);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.convert("PAYPALISHIRING", 3) << std::endl;
    return 0;
}