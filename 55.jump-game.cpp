/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        const auto last_it = nums.end() - 1;
        auto it = nums.begin();
        auto reachable_it = it;
        while (it <= reachable_it && reachable_it < last_it)
        {
            reachable_it = max(reachable_it, it + *it);
            it++;
        }
        return reachable_it >= last_it;
    }
};
// @lc code=end
