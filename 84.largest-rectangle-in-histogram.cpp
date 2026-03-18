/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        // TODO(sam): Reivew
        int ans = 0;
        stack<vector<int>::iterator> s;
        for (auto it = heights.begin(); it != heights.end(); it++)
        {
            auto l_it = it;
            while (!s.empty() && *s.top() >= *it)
            {
                l_it = s.top();
                s.pop();
                ans = max(ans, static_cast<int>(distance(l_it, it)) * *l_it);
            }
            *l_it = *it;
            s.push(l_it);
        }

        while (!s.empty())
        {
            auto l_it = s.top();
            s.pop();
            ans = max(ans, static_cast<int>(distance(l_it, heights.end())) * *l_it);
        }
        return ans;
    }
};
// @lc code=end
