/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    constexpr static size_t arr_size = 128;

  public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        array<int, arr_size> cnts{};
        for (const char ch : s)
        {
            cnts.at(ch)++;
        }

        for (const char ch : t)
        {
            if (!cnts.at(ch)--)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
