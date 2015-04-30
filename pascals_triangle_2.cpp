// #119 Pascal's Triangle II
//
// Given an index k, return the kth row of the Pascal's triangle.
//
// For example, given k = 3,
//
// Return [1,3,3,1].
//
// Note:
//
// Could you optimize your algorithm to use only O(k) extra space?


#include <iostream>
#include <vector>

using namespace std;

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> result;
        result.resize(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            int prev = result[0];
            for (int j = 0; j <= i; ++j) {
                if (0 == j || j == i) result[j] = 1;
                else {
                    int tmp = result[j] + prev;
                    prev = result[j];
                    result[j] = tmp;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    print(s.getRow(0));
    print(s.getRow(1));
    print(s.getRow(3));
    print(s.getRow(4));
    print(s.getRow(10));
    return 0;
}
