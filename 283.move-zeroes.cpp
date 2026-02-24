/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        auto it = nums.begin();
        for (const int num : nums)
        {
            if (num)
            {
                *it++ = num;
            }
        }
        while (it != nums.end())
        {
            *it++ = 0;
        }
        /*
        for (size_t i = 0, zero_cnt = 0; i < nums.size(); i++)
        {
            const int val = nums.at(i);
            if (!val)
            {
                zero_cnt++;
            }
            else
            {
                nums.at(i) = 0;
                nums.at(i - zero_cnt) = val;
            }
        }
        */
        /*
        for (size_t i = 0, j = 0; j < nums.size(); j++)
        {
            if (nums.at(j))
            {
                swap(nums.at(i++), nums.at(j));
            }
        }
        */
    }
};
// @lc code=end
