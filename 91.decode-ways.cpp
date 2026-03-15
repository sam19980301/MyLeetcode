/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int numDecodings(string s)
    {
        if (s.size() == 1 /* || s.front() == '0' */)
        {
            return s.front() == '0' ? 0 : 1;
        }

        int pprev = 1;
        int prev = 1;
        for (size_t i = 0; i < s.size(); i++)
        {
            const char curr_ch = s.at(i);
            const char prev_ch = i > 0 ? s.at(i - 1) : '0';
            int curr = 0;
            if (curr_ch != '0')
            {
                curr += prev;
            }
            if (((prev_ch == '1' || prev_ch == '2') && curr_ch == '0') || /* 10,20 */
                (prev_ch == '1') ||                                       /* 11-19 */
                (prev_ch == '2' && (curr_ch <= '6'))                      /* 21-26 */
            )
            {
                curr += pprev;
            }

            pprev = prev;
            prev = curr;
        }
        return prev;
    }
};
// @lc code=end
