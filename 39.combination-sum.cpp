/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void combinationSum_helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int ind, int target) {
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (target < 0)
            return;
        
        for (int i = ind; i < candidates.size(); i++)
        {
            curr.push_back(candidates[i]);
            combinationSum_helper(candidates, ans, curr, i, target - candidates[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum_helper(candidates, ans, curr, 0, target);
        return ans;
    }
};
// @lc code=end

