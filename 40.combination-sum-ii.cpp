/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void combinationSum2_helper(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int index, int target) {
        if (target == 0)
        {
            ans.push_back(curr);
            return ;
        }

        if (target < 0)
            return ;
        
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            curr.push_back(candidates[i]);
            combinationSum2_helper(candidates, ans, curr, i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum2_helper(candidates, ans, curr, 0, target);
        return ans;
    }
};
// @lc code=end

