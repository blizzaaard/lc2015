// #118 Pascal's Triangle
//
// Given numRows, generate the first numRows of Pascal's triangle.
//
// For example, given numRows = 5,
//
// Return
//
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


#include <iostream>
#include <vector>

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
    std::vector<std::vector<int> > generate(int numRows)
    {
        //  1
        //  1 1
        //  1 2 1
        //  1 3 3 1
        //  1 4 6 4 1

        vector<vector<int> > result;
        if (numRows < 1) return result;
        result.resize(1, vector<int>(1, 1));
        for (int i = 1; i < numRows; ++i) {
            result.resize(i + 1);
            for (int j = 0; j <= i; ++j) {
                if (0 == j || i == j) result[i].push_back(1);
                else result[i].push_back(result[i - 1][j - 1]
                                       + result[i - 1][j]);
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    {
        print(s.generate(0));
        print(s.generate(1));
        print(s.generate(2));
        print(s.generate(3));
        print(s.generate(4));
        print(s.generate(5));
    }
    return 0;
}
