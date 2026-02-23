/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int ans = static_cast<int>(nums.size() * (nums.size() + 1) / 2);
        for (const int num : nums)
        {
            ans -= num;
        }
        return ans;
        /*
        unsigned int ans = 0;
        for (const unsigned int num : nums)
        {
            ans ^= num;
        }
        for (unsigned int i = 0; i < nums.size() + 1; i++)
        {
            ans ^= i;
        }
        return static_cast<int>(ans);
        */
    }
};
// @lc code=end
