/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> cnts(amount + 1, INT_MAX);
        cnts[0] = 0;

        for (int i = 1; i <= amount; i++)
            for (int coin : coins)
                if (i - coin >= 0 && cnts[i - coin] != INT_MAX)
                    cnts[i] = min(cnts[i], 1 + cnts[i - coin]);
        return cnts.back() == INT_MAX ? -1 : cnts.back();
    }
};
// @lc code=end

