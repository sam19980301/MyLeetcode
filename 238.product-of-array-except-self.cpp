/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // TODO(sam): Review
        vector<int> ans(nums.size(), 1);
        auto l_it = ans.begin();
        int l_prod = 1;
        for (const int num : nums)
        {
            *l_it++ *= l_prod;
            l_prod *= num;
        }

        auto r_it = ans.rbegin();
        int r_prod = 1;
        for (const int num : ranges::reverse_view(nums))
        {
            *r_it++ *= r_prod;
            r_prod *= num;
        }
        return ans;
    }
};
// @lc code=end
