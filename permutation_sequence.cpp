// #60 Permutation Sequence
//
// The set [1,2,3,…,n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
//
// Given n and k, return the kth permutation sequence.
//
// Note: Given n will be between 1 and 9 inclusive.


#include <string>
#include <iostream>

class Solution {

    unsigned int factorial(unsigned int n)
    {
        static const unsigned int table[] = {
              1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
              479001600
        };
        return table[n];
    }

  public:
    std::string getPermutation(int n, int k)
    {
        --k;
        std::string result;
        std::string seq("123456789");
        while (1 < n) {
            int pos = k / factorial(n - 1);
            if (pos >= seq.size()) {
                return result;
            }
            result.push_back(seq[pos]);
            seq.erase(pos, 1);
            k %= factorial(n - 1);
            --n;
        }
        result.push_back(seq[0]);
        return result;
    }
};

int main()
{
    Solution s;
    std::cout << s.getPermutation(0, 0) << std::endl;
    std::cout << s.getPermutation(1, 0) << std::endl;
    std::cout << s.getPermutation(0, 1) << std::endl;
    std::cout << s.getPermutation(3, 50) << std::endl;
    std::cout << s.getPermutation(3, 5) << std::endl;
    return 0;
}
