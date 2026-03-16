/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 128;

  public:
    string minWindow(string s, string t)
    {
        array<int, arr_size> cnts{};
        int invalid_char_cnt = 0;
        for (const char ch : t)
        {
            if (!cnts.at(ch)--)
            {
                invalid_char_cnt++;
            }
        }

        auto st_it = s.begin();
        auto ed_it = s.begin();
        auto ans_st_it = s.begin();
        auto ans_ed_it = s.begin();
        auto ans_sz = numeric_limits<ptrdiff_t>::max();
        while (ed_it != s.end())
        {
            if (!++cnts.at(*ed_it++))
            {
                invalid_char_cnt--;
            }

            if (!invalid_char_cnt) // valid
            {
                while (cnts.at(*st_it) > 0)
                {
                    cnts.at(*st_it++)--;
                }

                auto sz = distance(st_it, ed_it);
                if (sz < ans_sz)
                {
                    ans_st_it = st_it;
                    ans_ed_it = ed_it;
                    ans_sz = sz;
                }
            }
        }

        return {ans_st_it, ans_ed_it};
    }
};
// @lc code=end
