/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // holding / not holding stock with at most k transactions finished after today
        vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(k + 1));
        for (int j = 0; j <= k; j++)
            dp[1][j].first = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            int price = prices[i];
            dp[0].swap(dp[1]);
            dp[1][0].first = max(dp[0][0].first, -price);
            for (int j = 1; j <= k; j++)
            {
                dp[1][j] = {
                    max(dp[0][j].first, dp[0][j].second - price),
                    max(dp[0][j].second, dp[0][j-1].first + price)
                };
            }
        }
        return dp.back().back().second;

        // vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(prices.size(), 0)));
        // for (int i = 0; i <= k; i++)
        //     dp[0][i][0] = -prices[0];
        // for (int j = 1; j < prices.size(); j++)
        //     dp[0][0][j] = max(dp[0][0][j-1], -prices[j]);
        // for (int j = 1; j < prices.size(); j++)
        // {
        //     int price = prices[j];
        //     for (int i = 1; i <= k; i++)
        //     {
        //         // holding stock
        //         dp[0][i][j] = max(dp[0][i][j-1], dp[1][i][j-1] - price);
        //         // not holding stock
        //         dp[1][i][j] = max(dp[1][i][j-1], dp[0][i-1][j-1] + price);
        //     }
        // }
        // return dp.back().back().back();
    }
};
// @lc code=end

