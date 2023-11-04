/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ans = 0, curr_start = intervals.back()[0];
        for (int i = intervals.size() - 2; i >= 0; i--)
        {
            if (curr_start < intervals[i][1])
                ans++;
            else
                curr_start = intervals[i][0];
        }
        return ans;
    }
};
// @lc code=end

