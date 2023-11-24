/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            lp(s[0...i]) = 2 + lp(s[1...i-1])            [ if s[0] == s[i] ]
                         = max(lp(s[0...i-1], s[1...i])) [ else ]
        */

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = 1;
        
        for (int l = 2; l <= s.size(); l++)
        {
            for (int i = 0; i + l <= s.size(); i++)
            {
                if (s[i] == s[i+l-1])
                    dp[i][i+l-1] = 2 + dp[i+1][i+l-2];
                else
                    dp[i][i+l-1] = max(dp[i+1][i+l-1], dp[i][i+l-2]);
            }
        }
        return dp.front().back();
    }
};
// @lc code=end

