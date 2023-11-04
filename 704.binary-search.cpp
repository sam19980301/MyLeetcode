/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else
                h = m;
        }
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end

