/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int mySqrt(int x)
    {
        int lo = 0;
        // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        int hi = 46340; // mySqrt((2^31)-1)
        while (lo < hi)
        {
            const int mid = lo + ((hi - lo) / 2);
            if (mid * mid <= x - (2 * mid) - 1) // (mid + 1) * (mid + 1) <= x
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        return lo;
    }
};
// @lc code=end
