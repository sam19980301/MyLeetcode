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
  public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        array<int, 128> cnts{};
        for (const unsigned char ch : s)
        {
            cnts.at(ch)++;
        }

        for (const unsigned char ch : t)
        {
            if (cnts.at(ch)-- == 0)
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
