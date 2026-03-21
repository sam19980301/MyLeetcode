/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        stack<int> st; // invalid indice,: either unused '(', or invalid ')'
        const int sz = static_cast<int>(s.size());
        for (int i = 0; i < sz; i++)
        {
            if (!st.empty() && s.at(st.top()) == '(' && s.at(i) == ')')
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
        /*
        int ans = 0;
        stack<int> st;
        st.push(-1);
        const int sz = static_cast<int>(s.size());
        for (int i = 0; i < sz; i++)
        {
            if (s.at(i) == '(')
            {
                st.push(i);
            }
            else // s.at(i) == ')'
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
        */
    }
};
// @lc code=end
