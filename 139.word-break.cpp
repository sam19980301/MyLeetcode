/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(1 + s.size(), false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++)
        {
            for (string& word : wordDict)
            {
                int pos = i - word.size();
                if (pos >= 0 && dp[pos] && s.substr(pos, word.size()) == word)
                    dp[i] = true;
            }
        }
        return dp.back();
    }
};
// @lc code=end

