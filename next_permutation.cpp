// #31 Next Permutation
//
// Implement next permutation, which rearranges numbers into the
// lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).
//
// The replacement must be in-place, do not allocate extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


#include <iostream>
#include <vector>

void print(const std::vector<int>& num)
{
    for (int i = 0; i < num.size(); ++i) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    void nextPermutation(std::vector<int>& num)
    {
        // Find the index of the first digit that is not in non-decreasing
        // order from right to left.

        int index = -1;
        for (int i = num.size() - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                index = i;
                break;
            }
        }

        // Find the index of the first digit that is larger than 'num[index]',
        // and swap this digit with 'num[index]'.

        if (-1 != index) {
            for (int i = num.size() - 1; i > index; --i) {
                if (num[i] > num[index]) {
                    int temp = num[i];
                    num[i] = num[index];
                    num[index] = temp;
                    break;
                }
            }
        }

        // Reverse the digits starting from 'num[index + 1]' to the end.

        std::reverse(num.begin() + index + 1, num.end());
    }
};

int main()
{
    {
        std::vector<int> data;
        data.push_back(1); data.push_back(2); data.push_back(3);
        Solution s;
        s.nextPermutation(data);
        print(data);
    }
    {
        std::vector<int> data;
        data.push_back(3); data.push_back(2); data.push_back(1);
        Solution s;
        s.nextPermutation(data);
        print(data);
    }
    {
        std::vector<int> data;
        data.push_back(1); data.push_back(5); data.push_back(1);
        Solution s;
        s.nextPermutation(data);
        print(data);
    }
    return 0;
}
