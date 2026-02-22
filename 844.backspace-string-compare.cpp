/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool backspaceCompare(string s, string t)
    {
        // TODO(sam): Review
        auto bs_increment = [](string::reverse_iterator it, string &str) -> string::reverse_iterator {
            int cnt = 0;
            while (it != str.rend() && (*it == '#' || cnt > 0))
            {
                if (*it == '#')
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }
                it++;
            }
            return it;
        };

        auto s_it = s.rbegin();
        auto t_it = t.rbegin();
        while (s_it != s.rend() || t_it != t.rend())
        {
            s_it = bs_increment(s_it, s);
            t_it = bs_increment(t_it, t);

            const bool s_valid = s_it != s.rend();
            const bool t_valid = t_it != t.rend();
            if (s_valid != t_valid)
            {
                return false;
            }
            if (s_valid /* && t_valid */ && *s_it++ != *t_it++)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
