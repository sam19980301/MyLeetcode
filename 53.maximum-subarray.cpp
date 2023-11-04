/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, maxsubarr_tail = 0;
        for (int num : nums)
        {
            maxsubarr_tail = num + max(0, maxsubarr_tail);
            ans = max(ans, maxsubarr_tail);
        }
        return ans;
    }
};
// @lc code=end

