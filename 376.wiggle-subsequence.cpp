/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans = 0;
        for (bool inc : { true, false } )
        {
            int len = 0, curr = inc ? INT_MAX : INT_MIN;
            for (int num : nums)
            {
                bool cond = (inc) ? (num < curr) : (num > curr);
                if (cond)
                {
                    len++;
                    inc = !inc;
                }
                curr = num;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

