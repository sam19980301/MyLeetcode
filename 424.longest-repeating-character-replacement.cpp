/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 'Z' - 'A' + 1;

  public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        array<int, arr_size> cnts{};
        int max_cnt = 0;
        auto l_it = s.begin();
        auto r_it = s.begin();
        while (r_it != s.end())
        {
            max_cnt = max(max_cnt, ++cnts.at(*r_it++ - 'A'));
            if (max_cnt + k < distance(l_it, r_it))
            {
                cnts.at(*l_it++ - 'A')--;
            }
            ans = max(ans, static_cast<int>(distance(l_it, r_it)));
        }
        return ans;

        /*
        array<int, arr_size> cnts{};
        int ans = k;
        auto l_it = s.begin();
        auto r_it = s.begin();
        while (r_it != s.end())
        {
            cnts.at(*r_it++ - 'A')++;
            while (*ranges::max_element(cnts, less<>()) + k < distance(l_it, r_it))
            {
                cnts.at(*l_it++ - 'A')--;
            }
            ans = max(ans, static_cast<int>(distance(l_it, r_it)));
        }
        return ans;
        */
    }
};
// @lc code=end
