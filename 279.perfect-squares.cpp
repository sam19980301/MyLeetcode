/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;
        for (int i = 1; i * i <= n; i++)
            arr.push_back(i * i);

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int ps : arr) // perfect square
            {
                if (i < ps)
                    break;
                dp[i] = min(dp[i], 1 + dp[i - ps]);
            }
        }
        return dp.back();
    }
};
// @lc code=end

