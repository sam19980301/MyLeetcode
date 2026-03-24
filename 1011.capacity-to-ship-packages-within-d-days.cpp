/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        auto get_required_days = [&weights](int capacity) {
            int required_days = 1;
            int remained_capacity = capacity;
            for (const int weight : weights)
            {
                if (remained_capacity < weight)
                {
                    remained_capacity = capacity;
                    required_days++;
                }
                remained_capacity -= weight;
            }
            return required_days;
        };

        int lo = ranges::max(weights, less<>());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi)
        {
            const int mid = lo + ((hi - lo) / 2);
            if (get_required_days(mid) > days)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};
// @lc code=end
