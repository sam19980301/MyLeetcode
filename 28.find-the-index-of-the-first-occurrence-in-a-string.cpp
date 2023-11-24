/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
            Notes (KMP reference): https://cp-algorithms.com/string/prefix-function.html
            Prefix function:
                pi[i] = max{ k : s[0 ... k-1] = s[i-(k-1) ... i] | 0 <= k <= i }
        */
                
        vector<int> pi(needle.size(), 0);
        for (int i = 1; i < needle.size(); i++)
        {
            int j = pi[i-1];
            while (j > 0 && needle[i] != needle[j])
                j = pi[j-1];
            if (needle[i] == needle[j])
                j++;
            pi[i] = j;
        }

        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            while (j > 0 && needle[j] != haystack[i])
                j = pi[j-1];
            if (needle[j] == haystack[i])
                if (++j == needle.size())
                    return i - needle.size() + 1;
        }
        return -1;
    }
};
// @lc code=end

