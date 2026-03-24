/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        return static_cast<int>(distance(nums.begin(), ranges::lower_bound(nums, target, less<>())));
        /*
        auto lo = nums.begin();
        auto hi = nums.end();
        while (lo < hi)
        {
            // 1 3 5 6
            //
            auto mid = lo + distance(lo, hi) / 2;
            if (*mid < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return static_cast<int>(distance(nums.begin(), lo));
        */
    }
};
// @lc code=end
