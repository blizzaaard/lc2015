
class Solution {

  public:
    string longestCommonPrefix(vector<string> &strs) {
        std::string result;  
        if (strs.size() < 1) {
            return result;
        }
        for (int i = 0; ; ++i) {
            if (i >= strs[0].size()) {
                return result;
            }
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return result;
                }
            }
            result.push_back(strs[0][i]);
        }
        return result;
    }
};

class Solution1 {

  public:
    string longestCommonPrefix(vector<string> &strings) {
        string result;
        if (strings.empty()) return result;
        int i = 0;
        while (1) {
            if (i >= strings[0].size()) return result;
            char c = strings[0][i];
            for (int j = 1; j < strings.size(); ++j) {
                if (i >= strings[j].size()) return result;
                if (c != strings[j][i]) return result;
            }
            result.push_back(c);
            ++i;
        }
        return result;
    }
};
