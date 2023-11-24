/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            non-cycle case
                rob(n) = max(money[n] + rob(n-2), rob(n-1))
        */
        
        // not robbing first house
        int prev = 0, curr = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int next = max(nums[i] + prev, curr);
            prev = curr;
            curr = next;
        }
        int ans = curr;

        // robbing first house
        prev = 0, curr = nums[0];
        for (int i = 1; i < nums.size() - 1; i++)
        {
            int next = max(nums[i] + prev, curr);
            prev = curr;
            curr = next;
        }
        ans = max(ans, curr);
        return ans;
    }
};
// @lc code=end

