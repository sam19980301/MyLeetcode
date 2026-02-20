/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        /*
            ans = max { profit sold at day i }
            profit sold at day i = { prices[i] - min {prices[0~i-1]} }
        */
        int best_buy_price = numeric_limits<int>::max();
        int profit = numeric_limits<int>::min();
        for (const int price : prices)
        {
            best_buy_price = min(best_buy_price, price);
            profit = max(profit, price - best_buy_price);
        }
        return profit;
    }
};
// @lc code=end
