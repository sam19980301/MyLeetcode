/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        // usuing unsigned int rather than int to avoid integer overflow
        vector<vector<unsigned int>> dp(2, vector<unsigned int>(t.size() + 1, 0));
        dp[0][0] = dp[1][0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            dp[0].swap(dp[1]);
            for (int j = 1; j <= t.size(); j++)
            {
                dp[1][j] = dp[0][j];
                if (s[i-1] == t[j-1])
                    dp[1][j] += dp[0][j-1];
            }
        }
        return dp.back().back();

        // vector<vector<unsigned int>> dp(s.size() + 1, vector<unsigned int>(t.size() + 1, 0));
        // for (int i = 0; i <= s.size(); i++)
        //     dp[i][0] = 1;
        // for (int j = 1; j <= t.size(); j++)
        //     dp[0][j] = 0;
        // for (int i = 1; i <= s.size(); i++)
        // {
        //     for (int j = 1; j <= t.size(); j++)
        //     {
        //         dp[i][j] = dp[i-1][j];
        //         if (s[i-1] == t[j-1])
        //             dp[i][j] += dp[i-1][j-1];
        //     }
        // }
        // return dp.back().back();
    }
};
// @lc code=end

