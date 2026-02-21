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
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        array<int, 128> cnts{};
        for (const unsigned char ch : magazine)
        {
            cnts.at(ch)++;
        }

        for (const unsigned char ch : ransomNote)
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
