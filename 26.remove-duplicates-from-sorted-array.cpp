/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        auto unique_it = nums.begin(); // [nums.begin(), unique_it)
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (it != nums.begin() && *it == *(it - 1))
            {
                continue;
            }

            *unique_it++ = *it;
        }
        return static_cast<int>(distance(nums.begin(), unique_it));
    }
};
// @lc code=end
