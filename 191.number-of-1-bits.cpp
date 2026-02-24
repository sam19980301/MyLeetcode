/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int hammingWeight(int n)
    {
        int cnt = 0;
        auto v = static_cast<unsigned int>(n);
        while (v)
        {
            v = v & (v - 1);
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end
