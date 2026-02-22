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
  private:
    constexpr static size_t arr_size = 128;

  public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        array<bool, arr_size> cnts{};
        for (const char ch : s)
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
