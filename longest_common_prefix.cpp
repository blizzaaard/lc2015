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