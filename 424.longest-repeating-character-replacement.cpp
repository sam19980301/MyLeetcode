/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, cnts[26]{ }, max_cnt = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            max_cnt = max(max_cnt, ++cnts[s[i]-'A']);
            while (i-l+1-max_cnt>k)
                cnts[s[l++]-'A']--;
            ans = max(ans, i-l+1);
        }
        return ans;

        // int l = 0, cnts[26]{ }, ans = 0;
        // for (int i = 0; i < s.size(); i++)
        // {
        //     cnts[s[i]-'A']++;
        //     while (i - l + 1 - *max_element(cnts + 0, cnts + 26) > k)
        //         cnts[s[l++]-'A']--;
        //     ans = max(ans, i-l+1);
        // }
        // return ans;
    }
};
// @lc code=end

