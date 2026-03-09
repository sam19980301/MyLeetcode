/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        for (const int num : nums)
        {
            auto it = ranges::lower_bound(lis, num, less<>());
            if (it == lis.end())
            {
                lis.push_back(num);
            }
            else
            {
                *it = num;
            }
        }
        return static_cast<int>(lis.size());
    }
};
// @lc code=end
