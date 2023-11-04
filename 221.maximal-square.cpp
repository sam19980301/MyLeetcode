/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = matrix[i][0] - '0';
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i] - '0';
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == '1')
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});

        int side = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                side = max(side, dp[i][j]);
        return side * side;
    }
};
// @lc code=end

