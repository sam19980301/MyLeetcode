/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
            4 5 6 7 0 1 2
            ^     ^     ^
        */
        int l = 0, h = nums.size() - 1;
        while (l < h)
        {
            int m = l + (h - l) / 2; // lower-mid
            if (nums[m] <= nums[h])
                h = m;
            else
                l = m + 1;
        }
        return nums[l];
    }
};
// @lc code=end

