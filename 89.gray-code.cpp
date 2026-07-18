/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> grayCode(int n)
    {
        vector<int> ans(1, 0);
        // Notes: must reserve first in case iterator being invalid after reallocation!
        ans.reserve(1U << static_cast<unsigned int>(n));
        for (unsigned int i = 1; cmp_less_equal(i, n); i++)
        {
            for (const int value : ranges::reverse_view(ans))
            {
                ans.push_back(value + static_cast<int>((1U << (i - 1))));
            }
        }
        return ans;
    }
};
// @lc code=end
