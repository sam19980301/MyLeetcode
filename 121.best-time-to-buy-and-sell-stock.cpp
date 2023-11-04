/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            ans = max { profit sold at day i }
            profit sold at day i = { prices[i] - min {prices[0~i-1]} }
        */
        int buy_price = INT_MAX, profit = 0;
        for (int price : prices)
        {
            profit = max(profit, price - buy_price);
            buy_price = min(buy_price, price);
        }
        return profit;
    }
};
// @lc code=end

