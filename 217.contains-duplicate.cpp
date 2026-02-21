/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (const int num : nums)
        {
            auto [it, success] = s.insert(num);
            if (!success)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
