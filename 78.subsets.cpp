/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void subsets_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int n) {
        if (n == nums.size())
        {
            ans.push_back(curr);
            return ;
        }
        subsets_helper(nums, ans, curr, n+1);
        curr.push_back(nums[n]);
        subsets_helper(nums, ans, curr, n+1);
        curr.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        subsets_helper(nums, ans, curr, 0);
        return ans;
    }
};
// @lc code=end

