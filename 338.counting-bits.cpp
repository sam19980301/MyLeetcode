/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        // Notes (bit manipulation reference): https://cp-algorithms.com/algebra/bit-manipulation.html
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i&(i-1)] + 1;
            // ans[i] = ans[i-(i&-i)] + 1;
            // ans[i] = ans[i/2] + (i%2);
        return ans;
    }
};
// @lc code=end

