/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        ranges::sort(nums, less<>{});

        vector<vector<int>> ans;
        auto it = nums.begin();
        while (it < nums.end())
        {
            auto l_it = it + 1;
            auto r_it = nums.end() - 1;
            while (l_it < r_it)
            {
                const int sum = *it + *l_it + *r_it;
                if (sum < 0)
                {
                    l_it++;
                }
                else if (sum > 0)
                {
                    r_it--;
                }
                else // sum == 0
                {
                    ans.push_back({*it, *l_it++, *r_it--});
                    while (l_it < r_it && *l_it == *(l_it - 1))
                    {
                        l_it++;
                    }
                    while (l_it < r_it && *r_it == *(r_it + 1))
                    {
                        r_it--;
                    }
                }
            }
            it++;
            while (it < nums.end() && *it == *(it - 1))
            {
                it++;
            }
        }
        return ans;
    }
};
// @lc code=end
