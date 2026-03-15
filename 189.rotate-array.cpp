/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        const int step = k % static_cast<int>(nums.size());
        ranges::reverse(nums.rbegin(), nums.rbegin() + step);
        ranges::reverse(nums.rbegin() + step, nums.rend());
        ranges::reverse(nums.begin(), nums.end());

        /*
        const size_t sz = nums.size();
        const size_t loop = gcd(sz, static_cast<size_t>(k)); // gcd(a, 0) = |a|
        for (size_t i = 0; i < loop; i++)
        {
            size_t idx = (i + k) % sz;
            while (idx != i)
            {
                swap(nums.at(i), nums.at(idx));
                idx = (idx + k) % sz;
            }
        }
        */
    }
};
// @lc code=end
