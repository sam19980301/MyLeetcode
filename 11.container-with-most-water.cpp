/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            int  lh = height[l], rh = height[r];
            if (lh < rh)
            {
                ans = max(ans, (r - l) * lh);
                l++;
            }
            else
            {
                ans = max(ans, (r - l) * rh);
                r--;
            }
        }
        return ans;
    }
};
// @lc code=end

