/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        /*
            Subarray is not allowed to be empty.
        */
        int ans = numeric_limits<int>::min();
        int max_tail_sum = 0;
        for (const int num : nums)
        {
            max_tail_sum = num + max(max_tail_sum, 0);
            ans = max(ans, max_tail_sum);
        }
        return ans;
    }
};
// @lc code=end
