/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int pair = 0;
        bool arr[128] { };
        for (char ch : s)
        {
            if (arr[ch])
                pair++;
            arr[ch] = !arr[ch];
        }
        
        // pair to length
        int len = pair * 2;
        if (len < s.size()) // (s.size() % 2 || len < s.size())
            len++;
        return len;
    }
};
// @lc code=end

