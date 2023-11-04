/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1, curr_h = 0, ans = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                curr_h = max(curr_h, height[l]);
                ans += curr_h - height[l];
                l++;
            }
            else
            {
                curr_h = max(curr_h, height[r]);
                ans += curr_h - height[r];
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

