/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> m; // num : index
        for (int i = 0; cmp_less(i, nums.size()); i++)
        {
            auto [it, success] = m.emplace(nums.at(i), i);
            if (success)
            {
                continue;
            }

            auto &[num, index] = *it;
            if (abs(index - i) <= k)
            {
                return true;
            }
            index = i;
        }
        return false;
    }
};
// @lc code=end
