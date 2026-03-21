/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        using Job = tuple<int, int, int>; // ed, st, profit
        const size_t sz = startTime.size();
        vector<Job> jobs;
        jobs.reserve(sz);
        for (size_t i = 0; i < sz; i++)
        {
            jobs.emplace_back(endTime.at(i), startTime.at(i), profit.at(i));
        }
        ranges::sort(jobs, less<>());

        map<int, int> m{{numeric_limits<int>::min(), 0}}; // end time : max profit
        for (auto &job : jobs)
        {
            auto [ed, st, profit] = job;
            auto curr_profit = (--m.upper_bound(st))->second + profit;
            auto prev_profit = m.rbegin()->second;
            if (curr_profit > prev_profit)
            {
                m[ed] = curr_profit;
            }
        }
        return m.rbegin()->second;

        /*
        using Job = tuple<int, int, int>; // ed, st, profit
        const size_t sz = startTime.size();
        vector<Job> jobs;
        jobs.reserve(sz);
        for (size_t i = 0; i < sz; i++)
        {
            jobs.emplace_back(endTime.at(i), startTime.at(i), profit.at(i));
        }
        ranges::sort(jobs, less<>());

        int max_profit = 0;
        map<int, int> m{{numeric_limits<int>::min(), 0}}; // end time : max profit
        for (auto &job : jobs)
        {
            auto [ed, st, profit] = job;
            const int ed_max_profit = max(
                // taking the job
                (--m.upper_bound(st))->second + profit,
                // not taking the job
                (--m.upper_bound(ed))->second);
            m[ed] = max(m[ed], ed_max_profit);
            max_profit = max(max_profit, ed_max_profit);
        }
        return max_profit;
        */
    }
};
// @lc code=end
