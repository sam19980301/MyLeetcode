/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        pair<size_t, size_t> ans_pr(0, 1); // st, len
        const size_t sz = s.size();
        vector<vector<bool>> dps(2, vector<bool>(1 + sz, true)); // even/odd-length dp
        for (size_t len = 2; len <= sz; len++)
        {
            vector<bool> &dp = dps.at(len & 1U);
            for (size_t st = sz - len, ed = sz; ed >= len; st--, ed--)
            {
                dp.at(ed) = false;
                if (dp.at(ed - 1) /* [st + 1, ed - 1) is palindrome */ && s.at(st) == s.at(ed - 1))
                {
                    dp.at(ed) = true;
                    ans_pr = make_pair(st, len);
                }
            }
        }
        return s.substr(ans_pr.first, ans_pr.second);
    }
};
// @lc code=end
