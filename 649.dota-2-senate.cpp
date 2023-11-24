/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string predictPartyVictory(string senate) {
        list<char> ls;
        int cnt_r = 0, cnt_d = 0;
        for (char ch : senate)
        {
            ls.push_back(ch);
            if (ch == 'R')
                cnt_r++;
            else
                cnt_d++;
        }

        int banned_r = 0, banned_d = 0;
        auto curr = ls.begin();
        while (cnt_d && cnt_r)
        {
            if (*curr == 'R')
            {
                if (banned_r)
                {
                    banned_r--;
                    curr = ls.erase(curr);
                }
                else
                {
                    banned_d++;
                    cnt_d--;
                    curr++;
                }
            }
            else
            {
                if (banned_d)
                {
                    banned_d--;
                    curr = ls.erase(curr);   
                }
                else
                {
                    banned_r++;
                    cnt_r--;
                    curr++;
                }
            }
            if (curr == ls.end())
                curr = ls.begin();
        }
        if (cnt_r == 0)
            return "Dire";
        return "Radiant";
    }
};
// @lc code=end

