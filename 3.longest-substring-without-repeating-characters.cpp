/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, h = 0, ans = 0;
        bool cnts[128]{ };
        while (h < s.size())
        {
            // remains [l, h] valid
            if (cnts[s[h]])
                cnts[s[l++]] = false;
            else
                cnts[s[h++]] = true;
            ans = max(ans, h - l);
        }
        return ans;
                
    }
};
// @lc code=end

