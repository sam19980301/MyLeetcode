/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool canPartition(vector<int> &nums)
    {
        ranges::sort(nums, less<>());
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
        {
            return false;
        }

        const int target = sum / 2;
        vector<bool> dp(1 + target);
        dp.front() = true;
        for (const int num : nums)
        {
            for (int i = target; i >= num; i--)
            {
                if (dp.at(i - num))
                {
                    dp.at(i) = true;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
