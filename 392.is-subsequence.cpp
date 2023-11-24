/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
            is_subseq(s[...i], t[...j]) = is_subseq(s[...i-1], t[...j-1])   [ if s[i] == t[j] ]
                                        = is_subseq(s[...i], t[...j-1])     [ else ]
        */
        vector<vector<bool>> dp(2, vector<bool>(s.size() + 1, false));
        dp[0][0] = true;
        dp[1][0] = true;
        for (int i = 1; i <= t.size(); i++)
        {
            dp[0].swap(dp[1]);
            for (int j = 1; j <= s.size(); j++)
            {
                if (t[i-1] == s[j-1])
                    dp[1][j] = dp[0][j-1];
                else
                    dp[1][j] = dp[0][j];
            }
        }
        return dp.back().back();

        // vector<vector<bool>> dp(t.size() + 1, vector<bool>(s.size() + 1, false));
        // for (int i = 0; i <= t.size(); i++)
        //     dp[i][0] = true;
        // for (int i = 1; i <= t.size(); i++)
        // {
        //     for (int j = 1; j <= s.size(); j++)
        //     {
        //         if (t[i-1] == s[j-1])
        //             dp[i][j] = dp[i-1][j-1];
        //         else
        //             dp[i][j] = dp[i-1][j];
        //     }
        // }
        // return dp.back().back();
    }
};
// @lc code=end

