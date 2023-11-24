/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr_len = 1, max_len = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i-1])
                curr_len++;
            else
                curr_len = 1;
            max_len = max(max_len, curr_len);
        }
        return max_len;
    }
};
// @lc code=end

