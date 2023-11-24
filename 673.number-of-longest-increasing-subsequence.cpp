/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /*
            length of longest increasing subsequence
            lis(nums[...i]) = max{ lis(nums[...j]) | j < i and nums[j] < nums[i] } + 1
        */

        // LIS with count
        vector<pair<int, int>> dp(nums.size(), { 1, 1 }); // length, count of sub-seq ends at nums[i]
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i].first < dp[j].first + 1)
                        dp[i] = { dp[j].first + 1, dp[j].second };
                    else if (dp[i].first == dp[j].first + 1)
                        dp[i] = { dp[j].first + 1, dp[i].second + dp[j].second };
                }
            }
        }

        int maxlen = 0, maxcount = 0;
        for (auto [len, count] : dp)
        {
            if (len > maxlen)
            {
                maxlen = len;
                maxcount = count;
            }
            else if (len == maxlen)
            {
                maxcount += count;
            }
        }
        return maxcount;
    }
};
// @lc code=end

