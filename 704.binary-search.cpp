/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        auto l_it = nums.begin();
        auto r_it = nums.end();
        while (l_it < r_it)
        {
            auto m_it = l_it + (r_it - l_it) / 2;
            if (*m_it < target)
            {
                l_it = m_it + 1;
            }
            else
            {
                r_it = m_it;
            }
        }

        if (l_it != nums.end() && *l_it == target)
        {
            return static_cast<int>(distance(nums.begin(), l_it));
        }
        return -1;
    }
};
// @lc code=end
