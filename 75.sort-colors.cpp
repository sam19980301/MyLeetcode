/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        // TODO(sam): Review
        // [begin, it_01): 0
        // [it_01, it_lo): 1
        // [it_lo, it_hi]: unordered
        // (it_hi, end): 2
        auto it_01 = nums.begin();
        auto it_lo = nums.begin();
        auto it_hi = nums.end() - 1;
        while (it_lo <= it_hi)
        {
            if (*it_lo == 0)
            {
                swap(*it_01++, *it_lo++);
            }
            else if (*it_lo == 1)
            {
                *it_lo++;
            }
            else // *it_lo == 2
            {
                swap(*it_lo, *it_hi--);
            }
        }
    }
};
// @lc code=end
