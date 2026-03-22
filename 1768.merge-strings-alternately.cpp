/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string mergeAlternately(string word1, string word2)
    {
        string ans;
        ans.reserve(word1.size() + word2.size());

        auto it_1 = word1.begin();
        auto it_2 = word2.begin();
        while (it_1 != word1.end() && it_2 != word2.end())
        {
            ans.push_back(*it_1++);
            ans.push_back(*it_2++);
        }
        if (it_1 != word1.end())
        {
            ans.insert(ans.end(), it_1, word1.end());
        }
        else
        {
            ans.insert(ans.end(), it_2, word2.end());
        }
        return ans;
    }
};
// @lc code=end
