/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int max_sum = sum;
        for (auto it = nums.begin() + k; it != nums.end(); it++)
        {
            sum += *it - *(it - k);
            max_sum = max(max_sum, sum);
        }
        return static_cast<double>(max_sum) / k;
    }
};
// @lc code=end
