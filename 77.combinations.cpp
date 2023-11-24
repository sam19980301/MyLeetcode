/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void combine_helper(int n, int k, vector<vector<int>>& ans, vector<int>& curr)
    {
        if (k == 0)
        {
            ans.push_back(curr);
            return ;
        }

        for (int i = curr.empty() ? 1 : curr.back() + 1; i <= n; i++)
        {
            curr.push_back(i);
            combine_helper(n, k - 1, ans, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        combine_helper(n, k, ans, curr);
        return ans;
    }
};
// @lc code=end

