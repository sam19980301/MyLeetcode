/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (const int asteroid : asteroids)
        {
            if (ans.empty() || ans.back() < 0 || asteroid > 0)
            {
                ans.push_back(asteroid);
                continue;
            }

            while (!ans.empty() && ans.back() > 0 && ans.back() + asteroid < 0)
            {
                ans.pop_back();
            }

            if (ans.empty() || ans.back() < 0)
            {
                ans.push_back(asteroid);
            }
            else if (ans.back() + asteroid == 0)
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};
// @lc code=end
