/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int stone : stones)
            sum += stone;
        int target = sum / 2;
        vector<bool> dp(1 + target, false);
        dp[0] = true;
        for (int stone : stones)
            for (int i = target; i >= stone; i--)
                dp[i] = dp[i] || dp[i-stone];
        for (int i = target; i >= 0; i--)
            if (dp[i])
                return sum - 2 * i;
        return -1;
    }
};
// @lc code=end

