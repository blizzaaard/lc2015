// #122 Best Time to Buy and Sell Stock II
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many
// transactions as you like (ie, buy one and sell one share of the stock
// multiple times). However, you may not engage in multiple transactions at the
// same time (ie, you must sell the stock before you buy again).


#include <iostream>
#include <vector>

class Solution {

  public:
    int maxProfit(std::vector<int>& prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += (prices[i] - prices[i - 1]);
            }
        }
        return profit;
    }
};

int main()
{
    Solution s;
    {
        std::vector<int> prices;
        prices.push_back(1);
        prices.push_back(2);
        prices.push_back(3);
        std::cout << s.maxProfit(prices) << std::endl;
    }
    return 0;
}
