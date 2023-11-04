/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /* find the min-valued index */
        int l = 0, h = nums.size() - 1;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] > nums[h])
                l = m + 1;
            else
                h = m;
        }
        int lo = l;

        l = 0, h = nums.size() - 1;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (nums[(m + lo) % nums.size()] < target)
                l = m + 1;
            else
                h = m;
        }
        l = (l + lo) % nums.size();
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end

