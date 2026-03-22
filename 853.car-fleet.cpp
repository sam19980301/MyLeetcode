/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        // TODO(sam): Review
        const size_t sz = position.size();
        vector<pair<int, int64_t>> cars; // position, speed
        cars.reserve(sz);
        for (size_t i = 0; i < sz; i++)
        {
            cars.emplace_back(position.at(i), speed.at(i));
        }
        ranges::sort(cars, less<>());

        int fleet = 1;
        auto [prev_position, prev_speed] = cars.back();
        for (auto [curr_position, curr_speed] : ranges::reverse_view(cars))
        {
            // arrived time = (target - car position) / car speed
            if (((target - curr_position) * prev_speed) > ((target - prev_position) * curr_speed)) // not catching up
            {
                prev_position = curr_position;
                prev_speed = curr_speed;
                fleet++;
            }
        }
        return fleet;
    }
};
// @lc code=end
