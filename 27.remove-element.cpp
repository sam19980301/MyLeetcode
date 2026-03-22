/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        auto l_it = nums.begin();
        auto r_it = nums.end();
        while (l_it < r_it)
        {
            if (*l_it == val)
            {
                swap(*l_it, *--r_it);
            }
            else
            {
                l_it++;
            }
        }
        return static_cast<int>(distance(nums.begin(), r_it));
    }
};
// @lc code=end
