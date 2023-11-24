/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
            change(amount, using coins[...i]) = change(amount, using coins[...i-1]) + change(amount - coins[i], using coins[...i-1])            
        */
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
            for (int i = coin; i <= amount; i++)
                dp[i] += dp[i-coin];
        return dp.back();
    }
};
// @lc code=end

