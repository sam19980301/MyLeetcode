/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size())
            return { };
        
        int cnts[26]{ }, cnt = 0;
        for (char ch : p)
            if (cnts[ch-'a']++ == 0)
                cnt++;
        
        vector<int> ans;        
        for (int i = 0; i < s.size(); i++)
        {
            int prev = i - p.size();
            if (prev >= 0 && ++cnts[s[prev]-'a'] == 1)
                cnt++;
            if (--cnts[s[i]-'a'] == 0)
                cnt--;
            if (cnt == 0)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
// @lc code=end

