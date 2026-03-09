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
        stack<vector<int>::reverse_iterator> s;
        for (auto temp_it = temperatures.rbegin(), ans_it = ans.rbegin(); temp_it != temperatures.rend();
             temp_it++, ans_it++)
        {
            while (!s.empty() && *temp_it >= *s.top())
            {
                s.pop();
            }
            if (!s.empty() && *temp_it < *s.top())
            {
                *ans_it = static_cast<int>(distance(s.top(), temp_it));
            }
            s.push(temp_it);
        }
        return ans;
    }
};
// @lc code=end
