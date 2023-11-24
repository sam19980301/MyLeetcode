/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> m(128, -1);
        vector<bool> mapped(128, false);
        for (int i = 0; i < s.size(); i++)
        {
            if (m[s[i]] < 0)
            {
                if (mapped[t[i]])
                    return false;
                mapped[t[i]] = true;
                m[s[i]] = t[i];
            }
            else if (m[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

