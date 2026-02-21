/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        array<bool, 128> cnts{};
        for (const unsigned char ch : s)
        {
            bool &is_odd = cnts.at(ch);
            if (is_odd)
            {
                ans += 2;
            }
            is_odd = !is_odd;
        }

        if (cmp_less(ans, s.size()))
        {
            ans++;
        }
        return ans;
    }
};
// @lc code=end
