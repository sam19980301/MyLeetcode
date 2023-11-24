/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            MED(x[...i], y[...j])   = MED(x[...i-1], y[...j-1])     [if x[i] == y[j]]
                                    = 1 + min(
                                        MED(x[...i-1], y[...j])     // insert x / delete y
                                        MED(x[...i], y[...j-1])     // delete y / insert x
                                        MED(x[...i-1], y[...j-1])   // replace
                                    )                               [else]
        */

        vector<vector<int>> dp(2, vector<int>(word2.size() + 1, 0));
        for (int j = 0; j <= word2.size(); j++)
            dp[1][j] = j;

        for (int i = 1; i <= word1.size(); i++)
        {
            dp[0].swap(dp[1]);
            dp[1][0] = i;
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i-1] == word2[j-1])
                    dp[1][j] = dp[0][j-1];
                else
                    dp[1][j] = 1 + min({ dp[1][j-1], dp[0][j], dp[0][j-1] });
            }
        }
        return dp.back().back();

        // vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // for (int i = 0; i <= word1.size(); i++)
        //     dp[i][0] = i;
        // for (int j = 0; j <= word2.size(); j++)
        //     dp[0][j] = j;
        // for (int i = 1; i <= word1.size(); i++)
        // {
        //     for (int j = 1; j <= word2.size(); j++)
        //     {
        //         if (word1[i-1] == word2[j-1])
        //             dp[i][j] = dp[i-1][j-1];
        //         else
        //             dp[i][j] = 1 + min({
        //                 dp[i-1][j-1],   // edit
        //                 dp[i][j-1],     // insert / delete
        //                 dp[i-1][j]      // insert / delete
        //             });
        //     }
        // }
        // return dp.back().back();
    }
};
// @lc code=end

