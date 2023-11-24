/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i-1];
        if (nums.front() == nums.back())
            return 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i-1] == nums.back() - nums[i])
                return i;
        return -1;
    }
};
// @lc code=end

