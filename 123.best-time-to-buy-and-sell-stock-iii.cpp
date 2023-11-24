/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(4, vector<int>(prices.size(), 0));
        dp[0][0] = -prices[0];
        dp[2][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            //     holding with at most 0 transaction finished after today
            dp[0][i] = max(dp[0][i-1], - prices[i]);
            // not holding with at most 1 transaction finished after today
            dp[1][i] = max(dp[1][i-1], dp[0][i-1] + prices[i]);
            //     holding with at most 1 transaction finished after today
            dp[2][i] = max(dp[2][i-1], dp[1][i-1] - prices[i]);
            // not holding with at most 2 transaction finished after today
            dp[3][i] = max(dp[3][i-1], dp[2][i-1] + prices[i]);
        }
        return dp.back().back();
    }
};
// @lc code=end

