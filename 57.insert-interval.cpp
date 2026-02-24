/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        auto it = intervals.begin();
        // on the left side of newInterval
        while (it != intervals.end() && it->back() < newInterval.front())
        {
            ans.push_back(*it++);
        }

        // overlapped w newInterval
        while (it != intervals.end() && it->front() <= newInterval.back())
        {
            newInterval.front() = min(it->front(), newInterval.front());
            newInterval.back() = max(it->back(), newInterval.back());
            it++;
        }
        ans.push_back(newInterval);

        // on the right side of newInterval
        while (it != intervals.end())
        {
            ans.push_back(*it++);
        }
        return ans;
    }
};
// @lc code=end
