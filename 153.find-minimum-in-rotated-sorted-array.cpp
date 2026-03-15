/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
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
        return *l_it;
    }
};
// @lc code=end
