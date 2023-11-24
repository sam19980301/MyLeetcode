/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 1, curr = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (curr < points[i][0])
            {
                ans++;
                curr = points[i][1];
            }
            else
            {
                curr = min(curr, points[i][1]);
            }
        }
        return ans;
    }
};
// @lc code=end

