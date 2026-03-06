/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int myAtoi(string s)
    {
        auto it = s.begin();
        while (it != s.end() && *it == ' ')
        {
            it++;
        }
        if (it == s.end())
        {
            return 0;
        }

        bool is_positive = true;
        if (*it == '-')
        {
            is_positive = false;
            it++;
        }
        else if (*it == '+')
        {
            is_positive = true;
            it++;
        }

        int64_t n = 0;
        while (it != s.end() && isdigit(*it))
        {
            // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
            n = (n * 10) + (*it++ - '0');
            if (is_positive && n >= numeric_limits<int32_t>::max())
            {
                return numeric_limits<int32_t>::max();
            }
            if (!is_positive && -n <= numeric_limits<int32_t>::min())
            {
                return numeric_limits<int32_t>::min();
            }
        }
        return static_cast<int>(is_positive ? n : -n);
    }
};
// @lc code=end
