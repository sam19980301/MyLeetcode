/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        ranges::sort(coins, less<>{});

        vector<int> cnts(amount + 1, numeric_limits<int>::max());
        cnts.at(0) = 0;

        for (int curr_amount = 0; curr_amount <= amount; curr_amount++)
        {
            for (const int coin : coins)
            {
                const int prev_amount = curr_amount - coin;
                if (prev_amount < 0)
                {
                    break;
                }
                if (cnts.at(prev_amount) != numeric_limits<int>::max())
                {
                    int &curr_cnt = cnts.at(curr_amount);
                    curr_cnt = min(curr_cnt, 1 + cnts.at(prev_amount));
                }
            }
        }
        return cnts.back() == numeric_limits<int>::max() ? -1 : cnts.back();
    }
};
// @lc code=end
