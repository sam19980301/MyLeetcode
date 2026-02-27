/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    constexpr static size_t arr_size = 128;

  public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        array<bool, arr_size> repeat{};
        auto l_it = s.begin();
        auto r_it = s.begin();
        while (r_it != s.end())
        {
            bool &is_repeated = repeat.at(*r_it);
            if (is_repeated)
            {
                repeat.at(*l_it++) = false;
            }
            else
            {
                is_repeated = true;
                ans = max(ans, static_cast<int>(++r_it - l_it)); // substring range: [l_it, r_it)
            }
        }
        return ans;
        /*
        int ans = 0;
        array<bool, arr_size> repeated{};
        auto l_it = s.begin();
        auto r_it = s.begin();
        while (r_it != s.end())
        {
            while (repeated.at(*r_it))
            {
                repeated.at(*l_it++) ^= true;
            }
            repeated.at(*r_it) ^= true;
            ans = max(ans, static_cast<int>(++r_it - l_it));
        }
        return ans;
        */
    }
};
// @lc code=end
