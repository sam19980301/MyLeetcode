/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int num : nums)
                if (i >= num && dp[i] <= INT_MAX - dp[i - num])
                    dp[i] += dp[i - num];
        return dp.back();
    }
};
// @lc code=end

