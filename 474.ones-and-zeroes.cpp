/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
            assume kth string contains x zeros and y ones
            maxform(m zeros, n ones, first k string) = max(
                maxform(m   zeros, n   ones, first k - 1 string),
                maxform(m-x zeros, n-y ones, first k - 1 string) + 1
            )
        */
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string& str : strs)
        {
            int zeros = 0, ones = 0;
            for (char ch : str)
                if (ch == '0')
                    zeros++;
                else
                    ones++;
            for (int i = m; i >= zeros; i--)
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
        }
        return dp.back().back();
    }
};
// @lc code=end

