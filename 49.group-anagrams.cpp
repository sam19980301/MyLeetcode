/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto &str : strs)
        {
            string key = str;
            ranges::sort(key, less<>());
            m[key].push_back(str);
        }

        vector<vector<string>> ans;
        ans.reserve(m.size());

        for (auto &[key, vector_strs] : m)
        {
            ans.push_back(vector_strs);
        }
        return ans;
    }
};
// @lc code=end
