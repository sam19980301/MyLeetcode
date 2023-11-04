/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            [0, i)          0
            [k + 1, ...)    2
        */
        int i = 0, j = 0, k = nums.size() - 1;
        while (j <= k)
        {
            if (nums[j] == 0)
                swap(nums[i++], nums[j++]);
            else if (nums[j] == 1)
                j++;
            else // nums[j] == 2
                swap(nums[j], nums[k--]);
        }
    }
};
// @lc code=end

