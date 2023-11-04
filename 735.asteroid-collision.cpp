/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int asteroid : asteroids)
        {
            if (ans.empty() || asteroid > 0)
            {
                ans.push_back(asteroid);
            }
            else
            {
                while (!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroid))
                    ans.pop_back();
                
                if (!ans.empty() && ans.back() == -asteroid)
                    ans.pop_back();
                else if (ans.empty() || ans.back() < 0)
                    ans.push_back(asteroid);
            }            
        }
        return ans;
    }
};
// @lc code=end

