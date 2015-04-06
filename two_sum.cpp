// #1 Two Sum
//
// Given an array of integers, find two numbers such that they add up to a
// specific target number.
//
// The function twoSum should return indices of the two numbers such that they
// add up to the target, where index1 must be less than index2. Please note
// that your returned answers (both index1 and index2) are not zero-based.
//
// You may assume that each input would have exactly one solution.
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2


#include <vector>
#include <iostream>
#include <unordered_map>

void print(const std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

class Solution {

  public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target)
    {
        typedef std::unordered_map<int, int> Hash;
            // The key is the expected number that can be added to the target
            // with the visited number, while the value is the index of the
            // visited number.

        std::vector<int> result;
        Hash             hash;
        for (int i = 0; i < numbers.size(); ++i) {
            Hash::iterator it = hash.find(numbers[i]);
            if (hash.end() == it) {
                hash.insert(std::make_pair(target - numbers[i], i));
            } else {
                result.push_back(it->second + 1);
                result.push_back(i + 1);
                return result;
            }
        }
        return result;
    }
};

using namespace std;
class Solution1 {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        print(numbers);
        std::sort(numbers.begin(), numbers.end());
        print(numbers);
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            } else if (numbers[start] + numbers[end] < target) {
                ++start;
            } else {
                --end;
            }
        }
        return result;
    }
};

int main()
{
    Solution1 s;
    {
        std::vector<int> numbers;
        numbers.push_back(3);
        numbers.push_back(2);
        numbers.push_back(4);

        print(s.twoSum(numbers, 6));
    }
    {
        std::vector<int> numbers;
        numbers.push_back(2);
        numbers.push_back(7);
        numbers.push_back(11);
        numbers.push_back(15);

        print(s.twoSum(numbers, 9));
    }

    return 0;
}
