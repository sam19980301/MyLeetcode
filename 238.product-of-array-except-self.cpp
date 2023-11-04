/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int prod = 1, ind_zero = -1;
        for (int i = 0; i< nums.size(); i++)
        {
            if (nums[i])
                prod *= nums[i];
            else
            {
                if (ind_zero >= 0)
                    return ans;
                ind_zero = i;
            }
        }

        if (ind_zero < 0)
        {
            for (int i = 0; i < nums.size(); i++)
                ans[i] = prod / nums[i];
        }
        else
        {
            ans[ind_zero] = prod;
        }
        return ans;

    }
};
// @lc code=end

