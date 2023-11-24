/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = nums.size();
        while (i < k)
        {
            if (nums[i] == val)
                swap(nums[i], nums[--k]);
            else
                i++;
        }
        return k;
    }
};
// @lc code=end

