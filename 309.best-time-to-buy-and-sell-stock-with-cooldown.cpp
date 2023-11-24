/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxhold = INT_MIN, maxnhold = 0, maxcool = 0;
        for (int price : prices)
        {
            // must awaiting for cooldown
            int next_maxhold = max(maxhold, maxcool - price);
            // selling allowed
            int next_maxnhold = max(maxnhold, maxhold + price);
            // in cooldown, not buying
            int next_maxcool = maxnhold;
            maxhold = next_maxhold;
            maxnhold = next_maxnhold;
            maxcool = next_maxcool;
        }
        return maxnhold;
    }
};
// @lc code=end

