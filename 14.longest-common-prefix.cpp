/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string &ref_str = strs.front();
        for (size_t i = 0; i < ref_str.size(); i++)
        {
            const char ch = ref_str.at(i);
            for (auto &str : strs)
            {
                if (i >= str.size() || ch != str.at(i))
                {
                    return ref_str.substr(0, i);
                }
            }
        }
        return ref_str;
    }
};
// @lc code=end
