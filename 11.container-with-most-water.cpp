/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int ans = 0;
        auto l_it = height.begin();
        auto r_it = height.end() - 1;
        while (l_it < r_it)
        {
            ans = max(ans, static_cast<int>(distance(l_it, r_it)) * min(*l_it, *r_it));
            const int l_val = *l_it;
            const int r_val = *r_it;
            if (l_val < r_val)
            {
                l_it++;
                while (l_it < r_it && *l_it <= l_val)
                {
                    l_it++;
                }
            }
            else
            {
                r_it--;
                while (l_it < r_it && *r_it <= r_val)
                {
                    r_it--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
