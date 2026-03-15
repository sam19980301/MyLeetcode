/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> ans(temperatures.size(), 0);
        stack<int> s;

        const int sz = static_cast<int>(temperatures.size());
        for (int i = 0; i < sz; i++)
        {
            while (!s.empty() && temperatures.at(i) > temperatures.at(s.top()))
            {
                ans.at(s.top()) = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;

        /*
        vector<int> ans(temperatures.size(), 0);
        stack<vector<int>::reverse_iterator> s;
        for (auto curr_it = temperatures.rbegin(), ans_it = ans.rbegin(); curr_it != temperatures.rend();
             curr_it++, ans_it++)
        {
            while (!s.empty() && *curr_it >= *s.top())
            {
                s.pop();
            }
            if (!s.empty() && *curr_it < *s.top())
            {
                *ans_it = static_cast<int>(distance(s.top(), curr_it));
            }
            s.push(curr_it);
        }
        return ans;
        */
    }
};
// @lc code=end
