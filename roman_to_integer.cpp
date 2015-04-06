class Solution {
public:
    int conv(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        int result = conv(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (conv(s[i]) <= conv(s[i - 1])) {
                result += conv(s[i]);
            } else {
                result += (conv(s[i]) - 2 * conv(s[i - 1]));
            }
        }
        return result;
    }
};