/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t arr_size = 128;

  public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
        {
            return false;
        }

        int unmatched_count = 0;
        array<int, arr_size> counts{};
        for (const char ch : s1)
        {
            if (!counts.at(ch)++)
            {
                unmatched_count++;
            }
        }

        for (size_t i = 0; i < s2.size(); i++)
        {
            if (!--counts.at(s2.at(i)))
            {
                unmatched_count--;
            }
            if (i >= s1.size() && !counts.at(s2.at(i - s1.size()))++)
            {
                unmatched_count++;
            }
            if (!unmatched_count)
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
