/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, start = 0, ans = INT_MAX;
        for (int end = 0; end < nums.size(); end++)
        {
            sum += nums[end];
            if (sum >= target)
            {
                while (sum >= target)
                    sum -= nums[start++];
                ans = min(ans, end - start + 2);
            }
        }
        return ans == INT_MAX ? 0 : ans;

        // while (end < nums.size() || sum >= target)
        // {
        //     if (sum >= target)
        //     {
        //         ans = min(ans, end - start);
        //         sum -= nums[start++];
        //     }
        //     else
        //     {
        //         sum += nums[end++];
        //     }
        // }
        // return ans == INT_MAX ? 0 : ans;
    }
};
// @lc code=end

