/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = 0;
        int ans_abs_diff = numeric_limits<int>::max();
        ranges::sort(nums, less<>());
        for (auto a_it = nums.begin(); a_it != nums.end(); a_it++)
        {
            auto b_it = a_it + 1;
            auto c_it = nums.end() - 1;
            while (b_it < c_it)
            {
                const int sum = *a_it + *b_it + *c_it;
                const int diff = sum - target;
                const int abs_diff = abs(diff);
                if (abs_diff < ans_abs_diff)
                {
                    ans = sum;
                    ans_abs_diff = abs_diff;
                }

                if (diff < 0)
                {
                    b_it++;
                }
                else
                {
                    c_it--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
