/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = 0;
        for (int num : nums)
            n += num;
        if (n % 2)
            return false;
        n /= 2;

        vector<bool> dp(1 + n, false);
        dp[0] = true;
        for (int num : nums)
        {
            for (int i = n; i >= 0; i--)
            {
                int j = i - num;
                if (j >= 0 && dp[j])
                    dp[i] = true;
            }
        }
        return dp.back();
    }
};
// @lc code=end

