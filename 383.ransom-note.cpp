/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    constexpr static size_t arr_size = 128;

  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        array<int, arr_size> cnts{};
        for (const char ch : magazine)
        {
            cnts.at(ch)++;
        }

        for (const char ch : ransomNote)
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
