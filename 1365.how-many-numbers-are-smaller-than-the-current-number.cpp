/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> snums(nums), ans(nums);
        sort(snums.begin(), snums.end());
        for (int i = 0; i < nums.size(); i++)
            ans[i] = lower_bound(snums.begin(), snums.end(), nums[i]) - snums.begin();
        return ans;
    }
};
// @lc code=end

