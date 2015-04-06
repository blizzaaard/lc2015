// #85 Maximal Rectangle
//
// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
// containing all ones and return its area.


#include <iostream>
#include <stack>
#include <vector>

class Solution {

    int largestRectangleArea(std::vector<int>& height)
        // This function is from #84 Largest Rectangle in Histogram.
    {
        height.push_back(0);
        std::stack<int> stack;
        int maxSum = 0;
        int i = 0;
        while (i < height.size()) {
            if (stack.empty() || height[i] >= height[stack.top()]) {
                stack.push(i);
                ++i;
            } else {
                int top = stack.top();
                stack.pop();
                if (stack.empty()) {
                    maxSum = std::max(maxSum, height[top] * i);
                } else {
                    maxSum = std::max(maxSum,
                                      height[top] * (i - stack.top() - 1));
                }
            }
        }
        return maxSum;
    }

  public:
    int maximalRectangle(std::vector<std::vector<char> > &matrix)
    {
        if (matrix.empty()) {
            return 0;
        }
        std::vector<int> height(matrix[0].size(), 0);
        int maxSum = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if ('1' == matrix[i][j]) {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }
            for (int k = 0; k < height.size(); ++k) {
                std::cout << height[k] << " ";
            }
            maxSum = std::max(maxSum, largestRectangleArea(height));
        }
        return maxSum;
    }
};

int main()
{
    std::vector<std::vector<char> > matrix(1);
    matrix[0].push_back('1');
    matrix[0].push_back('0');

    Solution s;
    std::cout << s.maximalRectangle(matrix) << std::endl;
    return 0;
}
