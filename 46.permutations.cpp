/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void permute_helper(vector<int>& nums, vector<vector<int>>& ans, int ind) {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[ind], nums[i]);
            permute_helper(nums, ans, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute_helper(nums, ans, 0);
        return ans;
    }
};
// @lc code=end

