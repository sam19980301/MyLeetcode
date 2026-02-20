/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        if (s.empty())
        {
            return true;
        }
        auto l_it = s.begin();
        auto r_it = s.end() - 1;
        while (l_it < r_it)
        {
            while (l_it < r_it && isalnum(*l_it) != 0)
            {
                l_it++;
            }
            while (l_it < r_it && isalnum(*r_it) != 0)
            {
                r_it--;
            }
            if (tolower(*l_it++) != tolower(*r_it--))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
