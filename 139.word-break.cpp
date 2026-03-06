/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(1 + s.size());
        dp.front() = true;
        for (size_t i = 1; i < dp.size(); i++)
        {
            for (const string &word : wordDict)
            {
                if (i < word.size())
                {
                    continue;
                }
                const size_t j = i - word.size();
                if (dp.at(j) && s.substr(j, word.size()) == word)
                {
                    dp.at(i) = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
