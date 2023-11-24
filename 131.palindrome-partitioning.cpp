/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void partition_helper(string& s, vector<vector<bool>>& dp, vector<vector<string>>& ans, vector<string>& curr, int index)
    {
        if (index == s.size())
        {
            ans.push_back(curr);
            return ;
        }

        for (int i = index; i < s.size(); i++)
        {
            if (dp[index][i])
            {
                curr.push_back(s.substr(index, i - index + 1));
                partition_helper(s, dp, ans, curr, i + 1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 1; i < s.size(); i++)
            dp[i][i-1] = true;
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = true;
        for (int l = 1; l < s.size(); l++) // length - 1
            for (int i = 0; i + l < s.size(); i++)
                dp[i][i+l] = (s[i] == s[i+l]) && dp[i+1][i+l-1];
        
        vector<vector<string>> ans;
        vector<string> curr;
        partition_helper(s, dp, ans, curr, 0);
        return ans;
    }
};
// @lc code=end

