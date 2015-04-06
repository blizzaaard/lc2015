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

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
      std::vector<int> getRow(int rowIndex)
      {
        std::vector<int> result;
        if (0 > rowIndex) {
            return result;
        }
        result.resize(rowIndex + 1, 0);
        for (int i = 0; i <= rowIndex; ++i) {
            int prev = 0;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    result[j] = 1;
                    prev      = 1;
                } else {
                    int newPrev = result[j];
                    result[j] = prev + result[j];
                    prev      = newPrev;
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
    return 0;
}
