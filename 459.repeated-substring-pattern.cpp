/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*
            assuming repeated substring t
                len(s) = k * len(t)
                pi = (k - 1) * len(t)
        */
        vector<int> pi(s.size(), 0);
        for (int i = 1; i < s.size(); i++)
        {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi.back() && (pi.back() % (s.size() - pi.back()) == 0);

        // auto same_substr = [&](int start, int l) -> bool {
        //     for (int i = 0; i < l; i++)
        //         if (s[i] != s[start++])
        //             return false;
        //     return true;
        // };

        // for (int l = 1; l < s.size(); l++)
        // {
        //     if (s.size() % l)
        //         continue;
            
        //     bool rsp = true;
        //     for (int i = 0; i + l - 1 < s.size() && rsp; i += l)
        //         if (!same_substr(i, l))
        //             rsp = false;
        //     if (rsp)
        //         return true;
        // }
        // return false;
    }
};
// @lc code=end

