/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
        {
            return {};
        }
        ranges::sort(nums, less<>());
        vector<vector<int>> ans;

        auto next_value = [](auto &it, auto ed, bool is_increment) {
            auto num = *it;
            if (is_increment)
            {
                it++;
                while (it < ed && *it == num)
                {
                    it++;
                }
            }
            else
            {
                it--;
                while (ed < it && *it == num)
                {
                    it--;
                }
            }
        };

        auto it_a = nums.begin();
        auto ed_a = nums.end() - 3;
        while (it_a != ed_a)
        {
            auto it_b = it_a + 1;
            auto ed_b = nums.end() - 2;
            while (it_b != ed_b)
            {
                const int64_t two_sum_target = static_cast<int64_t>(target) - *it_a - *it_b;
                auto it_c = it_b + 1;
                auto it_d = nums.end() - 1;
                while (it_c < it_d)
                {
                    const int64_t sum = *it_c + *it_d;
                    if (sum < two_sum_target)
                    {
                        it_c++;
                    }
                    else if (sum > two_sum_target)
                    {
                        it_d--;
                    }
                    else // sum == two_sum_target
                    {
                        ans.push_back({*it_a, *it_b, *it_c, *it_d});
                        next_value(it_c, it_d, true);
                        next_value(it_d, it_c, false);
                    }
                }
                next_value(it_b, ed_b, true);
            }
            next_value(it_a, ed_a, true);
        }
        return ans;
    }
};
// @lc code=end
