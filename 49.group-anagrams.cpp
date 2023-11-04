/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m; // there is no stl specialization for hash<vector<T>>
        for (string& str : strs)
        {
            string sort_str(str);
            sort(sort_str.begin(), sort_str.end());
            m[sort_str].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};
// @lc code=end

