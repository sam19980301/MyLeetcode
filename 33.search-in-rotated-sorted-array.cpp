/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        // find the shifted index
        auto l_it = nums.begin();
        auto r_it = nums.end() - 1;
        while (l_it < r_it)
        {
            auto m_it = l_it + distance(l_it, r_it) / 2;
            if (*m_it > *r_it)
            {
                l_it = m_it + 1;
            }
            else
            {
                r_it = m_it;
            }
        }
        auto shift_index = static_cast<int>(distance(nums.begin(), r_it));

        // trivial binary search
        size_t lo = 0;
        size_t hi = nums.size() - 1;
        while (lo < hi)
        {
            const size_t mid = lo + ((hi - lo) / 2);
            const int val = nums.at((shift_index + mid) % nums.size());
            if (val < target)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        lo = (lo + shift_index) % nums.size();
        return nums.at(lo) == target ? static_cast<int>(lo) : -1;
    }
};
// @lc code=end
