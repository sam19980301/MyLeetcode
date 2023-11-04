/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            rob(n) = max(money[n] + rob(n-2), rob(n-1))
        */
        
        int prev = 0, curr = 0;
        for (int num : nums)
        {
            int next = max(num + prev, curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
// @lc code=end

