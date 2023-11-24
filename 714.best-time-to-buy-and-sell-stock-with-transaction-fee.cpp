/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
            ans = maxproft_nhold(nth day)
            maxprofit_hold(nth day) = max(maxprofit_hold(n-1th day), maxprofit_nhold(nth day) - price(n))
            maxprofit_nhold(nth day) = max(maxprofit_nhold(n-1th day), maxprofit_hold(nth day) + price(n) - fee)
        */
        pair<int, int> curr = { -prices[0], 0 };
        for (int i = 1; i < prices.size(); i++)
            curr = {
                max(curr.first, curr.second - prices[i]),
                max(curr.second, curr.first + prices[i] - fee)
            };
        return curr.second;
    }
};
// @lc code=end

