/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < nums.size())
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else
                {
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                    while (j < k && nums[j-1] == nums[j])
                        j++;
                    while (j < k && nums[k+1] == nums[k])
                        k--;
                }
            }
            i++;
            while (i < nums.size() && nums[i-1] == nums[i])
                i++;
        }
        return ans;
    }
};
// @lc code=end

