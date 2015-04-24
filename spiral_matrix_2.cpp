// #59 Spiral Matrix II
//
// Given an integer n, generate a square matrix filled with elements from 1 to
// n2 in spiral order.
//
// For example,
//
// Given n = 3,
//
// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]


#include <vector>
#include <iostream>

void print(const std::vector<std::vector<int> >& result)
{
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {

  public:
    std::vector<std::vector<int> > generateMatrix(int n)
    {
        std::vector<std::vector<int> > result(n, std::vector<int>(n, 0));

        int topBound    = 0;
        int bottomBound = n - 1;
        int leftBound   = 0;
        int rightBound  = n - 1;

        int state = 0;
            // 0 - right; 1 - down; 2 - left; 3 - up
        int i = 0;
        int j = 0;
        int k = 0;
        while (1) {
            if (topBound > bottomBound && leftBound > rightBound) {
                break;
            }

            // When we hit the bound

            if (j > rightBound) {
                state = 1; // down
                --j;
                ++i;
                ++topBound;
                continue;
            } else if (i > bottomBound) {
                state = 2; // left
                --i;
                --j;
                --rightBound;
                continue;
            } else if (j < leftBound) {
                state = 3; // up
                ++j;
                --i;
                --bottomBound;
                continue;
            } else if (i < topBound) {
                state = 0; // right
                ++i;
                ++j;
                ++leftBound;
                continue;
            }

            // When we haven't hit the bound

            result[i][j] = ++k;

            if (0 == state) { // right
                ++j;
            } else if (1 == state) { // down
                ++i;
            } else if (2 == state) { // left
                --j;
            } else if (3 == state) { // up
                --i;
            }
        }
        return result;
    }
};

using namespace std;

class Solution1 {

  public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<vector<int> > result(n, vector<int>(n, 0));
        if (0 == n) return result;
        int count = 0;
        int i = 0, j = 0, state = 0;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        while (top <= bottom && left <= right) {
            if (j > right) {
                --j; ++i; state = 1; ++top;
            } else if (i > bottom) {
                --i; --j; state = 2; --right;
            } else if (j < left) {
                ++j; --i; state = 3; --bottom;
            } else if (i < top) {
                ++i; ++j; state = 0; ++left;
            } else {
                result[i][j] = ++count;
                if (0 == state) ++j;
                else if (1 == state) ++i;
                else if (2 == state) --j;
                else if (3 == state) --i;
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    {
        print(s.generateMatrix(1));
    }
    {
        print(s.generateMatrix(2));
    }
    {
        print(s.generateMatrix(3));
    }
    return 0;
}
