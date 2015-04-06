#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size() - 1;
        while (num[start] > num[end]) {
            int mid = start + (end - start) / 2;
            if (num[mid] < num[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return num[start];
    }
};

class Solution1 {
public:
    int findMin(vector<int> &num) {
        int start = 0, end = num.size() - 1;
        while (start < end) {
            int mid = start + (end - mid) / 2;
            if (num[mid] < num[end]) end = mid;
            else start = mid + 1;
        }
        return num[start];
    }
};

int main()
{
    Solution1 s;
    vector<int> num;
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(1);
    cout << s.findMin(num) << endl;
    return 0;
}

