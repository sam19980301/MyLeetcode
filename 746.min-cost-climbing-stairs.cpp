/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int curr = 0, prev = 0;
        for (int i = 1; i < cost.size(); i++)
        {
            int next = min(curr + cost[i], prev + cost[i-1]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
// @lc code=end

