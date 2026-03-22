/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool validPalindrome(string s)
    {
        // TODO(sam): Review
        auto is_pure_palindrome = [](string::iterator st_it, string::iterator ed_it) {
            while (st_it < ed_it)
            {
                if (*st_it++ != *ed_it--)
                {
                    return false;
                }
            }
            return true;
        };

        auto st_it = s.begin();
        auto ed_it = s.end() - 1;
        while (st_it < ed_it)
        {
            if (*st_it == *ed_it)
            {
                st_it++;
                ed_it--;
            }
            else if (is_pure_palindrome(st_it + 1, ed_it) || is_pure_palindrome(st_it, ed_it - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
