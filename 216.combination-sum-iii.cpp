/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    void combinationSum3_helper(vector<vector<int>>& ans, vector<int>& curr, int k, int target)
    {
        if (curr.size() == k)
        {
            if (target == 0)
            {
                ans.push_back(curr);
            }
            return ;
        }

        if (target > 0)
            return ;

        for (int i = curr.empty() ? 1 : curr.back() + 1; i <= 9; i++)
        {
            curr.push_back(i);
            combinationSum3_helper(ans, curr, k, target + i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinationSum3_helper(ans, curr, k, -n);
        return ans;
    }
};
// @lc code=end

