/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void findSubsequences_helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int index)
    {
        if (curr.size() >= 2)
            ans.push_back(curr);
        
        unordered_set<int> s;
        for (int i = index; i < nums.size(); i++)
        {
            if ((!curr.empty() && curr.back() > nums[i]) || s.find(nums[i]) != s.end())
                continue;
            s.insert(nums[i]);
            curr.push_back(nums[i]);
            findSubsequences_helper(nums, ans, curr, i + 1);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        findSubsequences_helper(nums, ans, curr, 0);
        return ans;
    }
};
// @lc code=end

