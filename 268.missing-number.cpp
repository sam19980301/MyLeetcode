/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size() * (nums.size() + 1) / 2;
        for (int num : nums)
            ans -= num;
        return ans;
    }
};
// @lc code=end

