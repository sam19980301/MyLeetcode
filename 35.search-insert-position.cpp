/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();

        // int lo = 0, hi = nums.size() - 1;
        // while (lo < hi)
        // {
        //     int mid = lo + (hi - lo) / 2;
        //     if (nums[mid] < target)
        //         lo = mid + 1;
        //     else
        //         hi = mid;
        // }
        // if (nums[lo] < target)
        //     lo++;
        // return lo;
    }
};
// @lc code=end

