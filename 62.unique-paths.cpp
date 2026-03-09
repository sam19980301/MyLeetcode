/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);
        while (--m)
        {
            for (auto it = dp.begin() + 1; it != dp.end(); it++)
            {
                *it += *(it - 1);
            }
        }
        return dp.back();
    }
};
// @lc code=end
