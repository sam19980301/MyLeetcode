/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2], ans_diff = ans - target;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int threesum = nums[i] + nums[j] + nums[k], diff = threesum - target;
                if (abs(diff) < abs(ans_diff))
                {
                    ans_diff = diff;
                    ans = threesum;
                }
                if (diff < 0)
                    j++;
                else
                    k--;
            }
        }
        return ans;
    }
};
// @lc code=end

