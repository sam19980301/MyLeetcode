/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unsigned int ans = 0;
        for (const unsigned int num : nums)
        {
            ans ^= num;
        }
        return static_cast<int>(ans);
    }
};
// @lc code=end
