/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        /*
            isp(s[i...j]) = (s[i] == s[j]) && isp(s[i+1...j-1])
        */
        vector<vector<bool>> isp(s.size(), vector<bool>(s.size(), false));
        for (int i = 1; i < s.size(); i++)
            isp[i][i-1] = true;
        for (int i = 0; i < s.size(); i++)
            isp[i][i] = true;
        for (int l = 1; l < s.size(); l++) // length - 1
            for (int i = 0; i + l < s.size(); i++)
                isp[i][i+l] = (s[i] == s[i+l]) && isp[i+1][i+l-1];
        
        /*
            mincut(s[0...i]) = 0                                                [ if isp(s[0...i]) ]
                             = 1 + min{ mincut(s[0...j]) | isp(s[j+1...i]) }    [ else ]
        */
        vector<int> mincut(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); i++)
        {
            if (isp[0][i])
            {
                mincut[i] = 0;
            }
            else
            {
                for (int j = 0; j < i; j++)
                    if (isp[j+1][i])
                        mincut[i] = min(mincut[i], mincut[j] + 1);
            }
        }
        return mincut.back();
    }
};
// @lc code=end

