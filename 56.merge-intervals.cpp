/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        ranges::sort(intervals, less<>());
        vector<vector<int>> ans;
        ans.push_back(intervals.front());
        for (auto &interval : intervals)
        {
            auto &curr_interval = ans.back();
            if (interval.front() <= curr_interval.back()) // overlap
            {
                curr_interval.back() = max(curr_interval.back(), interval.back());
            }
            else
            {
                ans.push_back(interval);
            }
        }
        return ans;
    }
};
// @lc code=end
