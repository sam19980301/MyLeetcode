/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        /*
            1 2 3 4 5 6  7  8  9 10 11 12
            0 1 2 4 6 9 12 18 27 36 54 81

            2 = 1 x 1
            3 = 1 x 2
            4 = 2 x 2
            5 = 2 x 3
            6 = 3 x 3
            7 = 2 x 2 x 3
            8 = 2 x 3 x 3
            9 = 3 x 3 x 3
           10 = 2 x 2 x 3 x 3
           11 = 2 x 3 x 3 x 3
           12 = 3 x 3 x 3 x 3
        */
        
        if (n <= 3)
            return n - 1;
        int ans = 1;
        while (n > 4)
        {
            ans *= 3;
            n -= 3;
        }
        ans *= n;
        return ans;

        // vector<int> dp(n + 1, 0);
        // for (int i = 2; i <= n; i++)
        //     for (int j = 1; j < i; j++)
        //         dp[i] = max(dp[i], j * max(i-j, dp[i-j]));
        // return dp.back();
    }
};
// @lc code=end

