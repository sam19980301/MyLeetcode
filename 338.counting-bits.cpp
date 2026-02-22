/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> countBits(int n)
    {
        // TODO(sam): Review 'Bit manipulation'
        vector<int> ans(n + 1);
        for (unsigned int i = 1; cmp_less_equal(i, n); i++)
        {
            ans.at(i) = 1 + ans.at(i & (i - 1));
            // ans.at(i) = 1 + ans.at(i - (i & (-i)));
            // ans.at(i) = static_cast<int>((i & 1U) + ans.at(i >> 1U));
        }
        return ans;
    }
};
// @lc code=end
