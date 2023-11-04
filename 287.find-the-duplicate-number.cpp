/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[abs(nums[i])-1] < 0)
        //         return abs(nums[i]);
        //     nums[abs(nums[i])-1] *= -1;
        // }
        // return -1; // will not happen

        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            if (i != nums[i]-1)
                return nums[i];
        }
        return -1; // will not happen
    }
};
// @lc code=end

