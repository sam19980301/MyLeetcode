/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        /*
            rob_money(i) = max(rob_money(i-1), rob_money(i-2) + nums[i])
        */
        int pprev = 0;
        int prev = 0;
        for (const int num : nums)
        {
            const int curr = max(prev, pprev + num);
            pprev = prev;
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end
