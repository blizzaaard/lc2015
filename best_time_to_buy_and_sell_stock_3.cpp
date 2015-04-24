// #123 Best Time to Buy and Sell Stock III
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two
// transactions.
//
// Note:
//
// You may not engage in multiple transactions at the same time (ie, you must
// sell the stock before you buy again).


#include <iostream>
#include <vector>

class Solution {

  public:
    int maxProfit(std::vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }

        // For each price, calculate the max profit until it from left to
        // right.

        std::vector<int> left(prices.size(), 0);

        int minimum = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            minimum = std::min(minimum, prices[i]);
            left[i] = std::max(left[i - 1], prices[i] - minimum);
        }

        // For each price, calculate the max profit until it from right to
        // left.

        std::vector<int> right(prices.size() + 1, 0);

        int maximum = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            maximum  = std::max(maximum, prices[i]);
            right[i] = std::max(right[i + 1], maximum - prices[i]);
        }

        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = std::max(maxProfit, left[i] + right[i + 1]);
            std::cout << maxProfit << " " << i << std::endl;
            std::cout << left[i] << " " << right[i] << std::endl;
        }
        return maxProfit;
    }
};

int main()
{
    Solution s;
//    {
//        std::vector<int> prices;
//        prices.push_back(1);
//        prices.push_back(2);
//        prices.push_back(3);
//        std::cout << s.maxProfit(prices) << std::endl;
//    }
    {
        std::vector<int> prices;
        prices.push_back(3);
        prices.push_back(2);
        prices.push_back(6);
        prices.push_back(5);
        prices.push_back(0);
        prices.push_back(3);
        std::cout << s.maxProfit(prices) << std::endl;
    }
    return 0;
}
