/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr int divisior = 10;

  public:
    int reverse(int x)
    {
        int n = 0;
        while (x)
        {
            auto [q, r] = div(x, divisior);
            if (x > 0 && n > (numeric_limits<int32_t>::max() - r) / divisior)
            {
                return 0;
            }
            if (x < 0 && n < (numeric_limits<int32_t>::min() - r) / divisior)
            {
                return 0;
            }
            n = (divisior * n) + r;
            x = q;
        }
        return n;
    }
};
// @lc code=end
