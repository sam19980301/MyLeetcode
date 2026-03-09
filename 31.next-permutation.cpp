/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        /*
            1 2 3 4
            1 2 4 3
            1 3 2 4
            1 3 4 2
            1 4 2 3
            1 4 3 2
            2 1 3 4
            2 1 4 3
            2 3 1 4
            2 3 4 1
            2 4 1 3
            2 4 3 1
            3 1 2 4
            3 1 4 2
            3 2 1 4
            3 2 4 1
            3 4 1 2
            3 4 2 1
            4 1 2 3
            4 1 3 2
            4 2 1 3
            4 2 3 1
            4 3 1 2
            4 3 2 1
        */

        // the last ascending pair
        auto r_it = nums.end() - 1;
        while (r_it != nums.begin() && *(r_it - 1) >= *r_it)
        {
            r_it--;
        }

        // put l_it into [r_it, end) in desceding order & sort it
        if (r_it != nums.begin())
        {
            auto l_it = r_it - 1;
            auto it = ranges::lower_bound(r_it, nums.end(), *l_it, greater<>()) - 1;
            swap(*l_it, *it);
        }
        ranges::reverse(r_it, nums.end());
    }
};
// @lc code=end
