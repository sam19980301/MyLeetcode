/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        auto it_s = s.rbegin(), it_t = t.rbegin();
        while (true)
        {
            int s_cnt = 0;
            while (it_s != s.rend() && (*it_s == '#' || s_cnt))
            {
                if (*it_s == '#')
                    s_cnt++;
                else
                    s_cnt--;
                it_s++;
            }

            int t_cnt = 0;
            while (it_t != t.rend() && (*it_t == '#' || t_cnt))
            {
                if (*it_t == '#')
                    t_cnt++;
                else
                    t_cnt--;
                it_t++;
            }

            // both end
            bool s_end = it_s == s.rend(), t_end = it_t == t.rend();
            if (s_end && t_end)
                return true;
            if ((s_end ^ t_end) || *it_s != *it_t)
                return false;
            it_s++;
            it_t++;
        }
        return true; // will not happen
    }
};
// @lc code=end

