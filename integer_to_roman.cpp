class Solution {
public:
    string intToRoman(int num) {
        std::string result;
        std::string symbol[] =
            { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
        int value[] =
            { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        int i = 0;
        while (0 != num) {
            while (num >= value[i]) {
                num -= value[i];
                result += symbol[i];
            }
            ++i;
        }
        return result;
    }
};
