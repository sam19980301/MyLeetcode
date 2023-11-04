/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] { };
        for (char ch : magazine)
            cnt[ch-'a']++;
        
        for (char ch : ransomNote)
            if (!cnt[ch-'a']--)
                return false;
        return true;
    }
};
// @lc code=end

