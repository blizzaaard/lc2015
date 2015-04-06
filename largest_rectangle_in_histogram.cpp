// #84 Largest Rectangle in Histogram
//
// Given n non-negative integers representing the histogram's bar height where
// the width of each bar is 1, find the area of largest rectangle in the
// histogram.
//
// Above is a histogram where width of each bar is 1, given height =
// [2,1,5,6,2,3].
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
// For example,
// Given height = [2,1,5,6,2,3],
// return 10.


#include <iostream>
#include <stack>
#include <vector>

class Solution_O2 {
    // Time complexity O(n2).  Space complexity O(1).

  public:
    int largestRectangleArea(std::vector<int>& height) {
        int maxSum = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i != height.size() - 1 && height[i] <= height[i + 1]) {
                continue;
            }
            int lowest = height[i];
            for (int j = i; j >= 0; --j) {
                lowest = std::min(lowest, height[j]);
                maxSum = std::max(maxSum, (i - j + 1) * lowest);
            }
        }
        return maxSum;
    }
};

class Solution {
    // Time complexity O(n).  Space complexity O(n).

  public:
    int largestRectangleArea(std::vector<int>& height)
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
};

using namespace std;

class Solution1 {
    // Time complexity O(n).  Space complexity O(n).

  public:
    int largestRectangleArea(vector<int> &height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (i != 0 && height[i - 1] >= height[i]) continue;
            int minimum = height[i];
            for (int j = i; j < height.size(); ++j) {
                minimum = min(minimum, height[j]);
                maxArea = max(maxArea, minimum * (j - i + 1));
            }
        }
        return maxArea;
    }
};

int main()
{
    Solution1 s;
    {
        std::vector<int> height(100000, 0);
        for (int i = 1; i < height.size(); ++i) {
            height[i] = 100000 - i;
        }
        std::cout << s.largestRectangleArea(height) << std::endl;
    }
//    {
//        std::vector<int> height(100000, 0);
//        for (int i = 0; i < 100000; ++i) {
//            height[i] = i;
//        }
//        std::cout << s.largestRectangleArea(height) << std::endl;
//    }
    {
        std::vector<int> height;
        height.push_back(4);
        height.push_back(2);
        height.push_back(0);
        height.push_back(3);
        height.push_back(2);
        height.push_back(5);

        std::cout << s.largestRectangleArea(height) << std::endl;
    }

    return 0;
}
