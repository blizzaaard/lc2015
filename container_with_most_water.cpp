// #11 Container with Most Water
//
// Given n non-negative integers a1, a2, ..., an, where each represents a point
// at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
// with x-axis forms a container, such that the container contains the most
// water.
//
// Note: You may not slant the container.


#include <vector>
#include <iostream>

class Solution {

  public:
    int maxArea(const std::vector<int>& height)
    {
        int maximum = 0;
        int left    = 0;
        int right   = height.size() - 1;
        while (left < right) {
            maximum = std::max(
                        maximum,
                        std::min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maximum;
    }
};

using namespace std;

class Solution1 {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        for (int i = 1; i < height.size(); ++i) {
            int area = 0;
            if (height[i] >= height[i - 1]) continue;
            int left = i - 1;
            for (int right = i + 1; right < height.size(); ++right) {
                int h = max(0, min(height[left], height[right]) - height[i]);
                area += (right - i) * h;
            }
            if (maxArea < area) maxArea = area;
        }
        return maxArea;
    }
};

int main()
{
    std::vector<int> height;
    height.push_back(1);
    height.push_back(2);

    Solution1 s;
    std::cout << s.maxArea(height) << std::endl;

    return 0;
}
