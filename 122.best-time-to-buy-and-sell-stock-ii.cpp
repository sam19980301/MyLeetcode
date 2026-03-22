/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        // TODO(sam): Solve it in DP approach
        int profit = 0;
        int buy_price = numeric_limits<int>::max();
        for (const int price : prices)
        {
            if (buy_price < price)
            {
                profit += price - buy_price;
            }
            buy_price = price;
        }
        return profit;
    }
};
// @lc code=end
