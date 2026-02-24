/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        auto l_it = nums.begin();
        auto r_it = nums.end() - 1;
        auto ans_it = ans.rbegin();
        while (l_it <= r_it)
        {
            const int lv = *l_it;
            const int rv = *r_it;
            if (abs(lv) > abs(rv))
            {
                *ans_it++ = lv * lv;
                l_it++;
            }
            else
            {
                *ans_it++ = rv * rv;
                r_it--;
            }
        }
        return ans;
    }
};
// @lc code=end
