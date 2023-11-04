/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        
        int count[26]{ };
        for (char ch : s)
            count[ch-'a']++;
        
        for (char ch : t)
            if (!count[ch-'a']--)
                return false;
        return true;
    }
};
// @lc code=end

