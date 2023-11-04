/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int l = 0, h = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (abs(nums[l]) > abs(nums[h]))
            {
                ans[i] = nums[l] * nums[l];
                l++;
            }
            else
            {
                ans[i] = nums[h] * nums[h];
                h--;
            }
        }
        return ans;
    }
};
// @lc code=end

