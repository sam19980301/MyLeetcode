/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int reverseBits(int n)
    {
        unsigned int ans = 0;
        for (unsigned int i = 0; i < numeric_limits<uint32_t>::digits; i++)
        {
            ans = ans << 1U | ((static_cast<unsigned>(n) >> i) & 1U);
        }
        return static_cast<int>(ans);
        /*
        unsigned int ans = n;
        // NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        ans = ((ans & 0xffff0000U) >> 16U) | ((ans & 0x0000ffffU) << 16U);
        ans = ((ans & 0xff00ff00U) >> 8U) | ((ans & 0x00ff00ffU) << 8U);
        ans = ((ans & 0xf0f0f0f0U) >> 4U) | ((ans & 0x0f0f0f0fU) << 4U);
        ans = ((ans & 0xccccccccU) >> 2U) | ((ans & 0x33333333U) << 2U);
        ans = ((ans & 0xaaaaaaaaU) >> 1U) | ((ans & 0x55555555U) << 1U);
        // NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
        return static_cast<int>(ans);
        */
    }
};
// @lc code=end
