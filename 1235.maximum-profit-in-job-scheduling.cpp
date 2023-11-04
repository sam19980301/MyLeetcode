/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int, int, int>> intervals;
        for (int i = 0; i < startTime.size(); i++)
            intervals.push_back({ endTime[i], startTime[i], profit[i] });
        sort(intervals.begin(), intervals.end());

        map<int, int> m; // endtime : profit
        m[INT_MIN] = 0;

        for (tuple<int, int, int>& interval : intervals)
        {
            m[get<0>(interval)] = max(
                prev(m.upper_bound(get<0>(interval)))->second,
                prev(m.upper_bound(get<1>(interval)))->second + get<2>(interval)
            );
        }
        return m.rbegin()->second;
    }
};
// @lc code=end

