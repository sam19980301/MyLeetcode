/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<vector<int>> dp(2, vector<int>(1 + nums2.size(), 0));
        for (int i = 0; i < nums1.size(); i++)
        {
            dp[0].swap(dp[1]);
            for (int j = 0; j < nums2.size(); j++)
            {
                dp[1][1 + j] = (nums1[i] == nums2[j]) ? 1 + dp[0][j] : 0;
                ans = max(ans, dp[1][1 + j]);
            }
        }
        return ans;
    }
};
// @lc code=end

