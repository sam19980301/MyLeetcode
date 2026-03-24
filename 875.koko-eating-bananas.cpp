/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        auto get_required_hours = [&piles](const int speed) {
            int hours = 0;
            for (const int pile : piles)
            {
                hours += (pile + speed - 1) / speed;
            }
            return hours;
        };

        int lo = 1;
        int hi = ranges::max(piles, less<>());
        while (lo < hi)
        {
            const int mid = lo + ((hi - lo) / 2);
            if (get_required_hours(mid) > h)
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
