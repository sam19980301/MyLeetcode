/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = true;
        for (int i = 1; i < s.size(); i++)
            dp[i][i-1] = true;
        
        for (int l = 2; l <= s.size(); l++)
            for (int i = 0; i+l <= s.size(); i++)
                if (s[i] == s[i+l-1])
                    dp[i][i+l-1] = dp[i+1][i+l-2];
                    
        int ans = -s.size() + 1;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < s.size(); j++)
                ans += dp[i][j];
        return ans;
    }
};
// @lc code=end

