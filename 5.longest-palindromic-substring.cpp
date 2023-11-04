/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        pair<int, int> pr = { 1, 0 };
        vector<vector<bool>> dps(2, vector<bool>(s.size(), true));
        for (int i = 2; i <= s.size(); i++)
        {
            vector<bool>& dp = dps[i%2];
            for (int j = s.size() - 1; j >= i - 1; j--)
            {
                dp[j] = false;
                if (dp[j-1] && s[j-i+1] == s[j])
                {
                    dp[j] = true;
                    pr = max(pr, { i, j });
                }
            }
        }
        return s.substr(pr.second - pr.first + 1, pr.first);
    }
};
// @lc code=end

