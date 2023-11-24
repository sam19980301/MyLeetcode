/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxhold = INT_MIN, maxnhold = 0;
        for (int price : prices)
        {
            int next_maxhold = max(maxhold, maxnhold - price);
            int next_maxnhold = max(maxnhold, maxhold + price);
            maxhold = next_maxhold;
            maxnhold = next_maxnhold;
        }
        return maxnhold;

        // vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        // dp[0][0] = -prices[0];
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     // holding a stock
        //     dp[0][i] = max(dp[0][i-1], dp[1][i-1] - prices[i]);
        //     // not holding a stock
        //     dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]);
        // }
        // return dp.back().back();

        // int ans = 0;
        // for (int i = 1; i < prices.size(); i++)
        //     ans += max(prices[i] - prices[i-1], 0);
        // return ans;
    }
};
// @lc code=end

