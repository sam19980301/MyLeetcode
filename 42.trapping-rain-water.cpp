/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int curr_height = 0;
        auto l_it = height.begin();
        auto r_it = height.end() - 1;
        while (l_it < r_it)
        {
            if (*l_it < *r_it)
            {
                curr_height = max(curr_height, *l_it);
                ans += curr_height - *l_it++;
            }
            else
            {
                curr_height = max(curr_height, *r_it);
                ans += curr_height - *r_it--;
            }
        }
        return ans;

        /*
        int ans = 0;
        stack<vector<int>::iterator> s;
        for (auto r_it = height.begin(); r_it != height.end(); r_it++)
        {
            int prev_level = 0;
            while (!s.empty())
            {
                auto l_it = s.top();
                const int curr_width = static_cast<int>(distance(l_it, r_it)) - 1;
                const int curr_level = min(*l_it, *r_it);
                ans += curr_width * (curr_level - prev_level);
                prev_level = curr_level;

                if (*l_it <= *r_it)
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            s.push(r_it);
        }
        return ans;
        */
    }
};
// @lc code=end
