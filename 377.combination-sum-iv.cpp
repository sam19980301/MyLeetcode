/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int combinationSum4(vector<int> &nums, int target)
    {
        vector<unsigned int> dp(target + 1);
        dp.at(0) = 1;
        for (int i = 1; i <= target; i++)
        {
            for (const int num : nums)
            {
                if (i >= num)
                {
                    dp.at(i) += dp.at(i - num);
                }
            }
        }
        return static_cast<int>(dp.back());
    }
};
// @lc code=end
