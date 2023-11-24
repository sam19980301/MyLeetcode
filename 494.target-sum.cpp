/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void findTargetSumWays_helper(vector<int>& nums, int& ans, int target, int index)
    {
        if (target < 0)
            return ;
        
        if (nums.size() == index)
        {
            if (target == 0)
                ans++;
            return ;
        }
        findTargetSumWays_helper(nums, ans, target, index + 1);
        findTargetSumWays_helper(nums, ans, target - nums[index], index + 1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int num : nums)
            sum += num;
        if ((sum - target) % 2)
            return 0;
        target = (sum - target) / 2;
        int ans = 0;
        findTargetSumWays_helper(nums, ans, target, 0);
        return ans;
    }
};
// @lc code=end

