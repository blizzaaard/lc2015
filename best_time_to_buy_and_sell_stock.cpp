// #123 Best Time to Buy and Sell Stock
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy one
// and sell one share of the stock), design an algorithm to find the maximum
// profit.


#include <vector>
#include <iostream>

class Solution {

  public:
    int maxProfit(const std::vector<int>& prices)
    {
        if (prices.empty()) {
            return 0;
        }
        int minimum = prices[0]; // local min price ending at prices[i]
        int maximum = 0;         // global max profit ending at prices[i]
        for (int i = 1; i < prices.size(); ++i) {
            minimum = std::min(minimum, prices[i]);
            maximum = std::max(maximum, prices[i] - minimum);
        }
        return maximum;
    }
};

int main()
{
    std::vector<int> prices;
    prices.push_back(1);
    Solution s;
    std::cout << s.maxProfit(prices) << std::endl;
    return 0;
}
