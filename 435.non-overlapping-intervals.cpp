/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = 0;
        ranges::sort(intervals, less<>());
        int curr_end = numeric_limits<int>::min();
        for (auto &interval : intervals)
        {
            if (curr_end > interval.front()) // overlapped
            {
                ans++;
                curr_end = min(curr_end, interval.back());
            }
            else // not overlapped
            {
                curr_end = interval.back();
            }
        }
        return ans;
    }
};
// @lc code=end
