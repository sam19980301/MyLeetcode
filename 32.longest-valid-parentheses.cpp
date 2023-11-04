/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            // match parentheses
            if (!st.empty() && s[st.top()] == '(' && s[i] == ')') 
            {
                st.pop();
                ans = max(ans, i - (st.empty() ? -1 : st.top()));
            }
            else
            {
                st.push(i);
            }
        }
        return ans;

        // int ans = 0;
        // vector<int> dp(s.size(), 0);
        // for (int i = 1; i < s.size(); i++)
        // {
        //     if (s[i] == ')')
        //     {
        //         if ((i-dp[i-1]-1>=0) && s[i-dp[i-1]-1] == '(')
        //             dp[i] = 2 + dp[i-1];
        //         if (i-dp[i]>=0)
        //             dp[i] += dp[i-dp[i]];
        //     }
        //     ans = max(ans, dp[i]);
        // }
        // return ans;
    }
};
// @lc code=end

