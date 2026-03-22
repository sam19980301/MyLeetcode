/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        // TODO(sam): Review & optimize: complexity could be O(n)

        // cumsum
        for (auto it = nums.begin() + 1; it != nums.end(); it++)
        {
            *it += *(it - 1);
        }

        /*
            sum([lo, hi]) >= target
            sum([st, hi]) - sum([st, lo - 1]) >= target
            find lo s.t. nums.at(lo - 1) <= nums.at(hi) - target
        */
        int ans = numeric_limits<int>::max();
        for (auto r_it = ranges::lower_bound(nums, target, less<>()); r_it != nums.end(); r_it++)
        {
            auto l_it = ranges::upper_bound(nums.begin(), r_it + 1, *r_it - target, less<>());
            if (l_it <= r_it)
            {
                ans = min(ans, static_cast<int>(distance(l_it, r_it) + 1));
            }
        }
        return ans != numeric_limits<int>::max() ? ans : 0;
    }
};
// @lc code=end
