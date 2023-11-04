/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s; // ascending height, {x, h}

        int ans = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int li = i, height = heights[i];
            while (!s.empty() && height <= s.top().second)
            {
                ans = max(ans, (i - s.top().first) * s.top().second);
                li = s.top().first;
                s.pop();
            }
            s.push({ li, height });
        }

        while (!s.empty())
        {
            ans = max(ans, ((int) heights.size() - s.top().first) * s.top().second);
            s.pop();
        }

        return ans;
    }
};
// @lc code=end

