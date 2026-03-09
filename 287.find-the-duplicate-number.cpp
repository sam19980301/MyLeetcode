/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int findDuplicate(vector<int> &nums)
    {
        while (nums.front() != nums.at(nums.front()))
        {
            swap(nums.front(), nums.at(nums.front()));
        }
        return nums.front();
    }
};
// @lc code=end
