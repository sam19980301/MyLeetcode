/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        
        int step = 1, curr = 0, reachable = nums[0];
        while (reachable < nums.size() - 1)
        {
            step++;
            int next_reachable = INT_MIN;
            for (; curr <= reachable; curr++)
                next_reachable = max(next_reachable, curr + nums[curr]);
            reachable = next_reachable;
        }
        return step;
    }
};
// @lc code=end

