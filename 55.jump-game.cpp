/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = 0, reachable = 0;
        while (curr <= reachable && reachable < nums.size() - 1)
        {
            reachable = max(reachable, curr + nums[curr]);
            curr++;
        }
        return reachable >= nums.size() - 1;
    }
};
// @lc code=end

