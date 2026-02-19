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
        unordered_map<int, size_t> m;
        for (size_t i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            auto it = m.find(target - val);
            if (it != m.end())
                return {(int)it->second, (int)i};
            m[val] = i;
        }
        return {};
    }
};
// @lc code=end
