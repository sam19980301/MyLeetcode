/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        int val = 0;
        int cnt = 0;
        for (const int num : nums)
        {
            if (cnt <= 0 || num == val)
            {
                val = num;
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        return val;
    }
};
// @lc code=end
