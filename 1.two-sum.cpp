/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> m;
        for (auto v_it = nums.begin(); v_it != nums.end(); v_it++)
        {
            auto m_it = m.find(target - *v_it);
            const int idx = static_cast<int>(v_it - nums.begin());
            if (m_it != m.end())
            {
                return {m_it->second, idx};
            }
            m[*v_it] = idx;
        }
        return {};
    }
};
// @lc code=end
