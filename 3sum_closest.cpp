class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (3 > num.size()) {
            return 0;
        }
        int result = num[0] + num[1] + num[2];
        int diff   = std::abs(result - target);
        std::sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue;
            }
            int left = i + 1, right = num.size() - 1;
            while (left < right) {
                int sum = num[i] + num[left] + num[right];
                if (diff > std::abs(sum - target)) {
                    diff = std::abs(sum - target);
                    result = sum;
                }
                if (target == sum) {
                    return target;
                } else if (target < sum) {
                    --right;
                } else {
                    ++left;
                }
            }
        }
        return result;
    }
};