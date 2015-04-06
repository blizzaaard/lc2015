class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size() - 1;
        while (num[start] >= num[end]) {
            int mid = start + (end - start) / 2;
            if (num[mid] == num[end]) {
                --end;
            } else if (num[mid] < num[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return num[start];
    }
};