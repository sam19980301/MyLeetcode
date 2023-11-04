/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch : s)
        {
            if (ch == '(')
                stk.push(')');
            else if (ch == '{')
                stk.push('}');
            else if (ch == '[')
                stk.push(']');
            else if (!stk.empty() && ch == stk.top())
                stk.pop();
            else
                return false;
        }
        return stk.empty();
    }
};
// @lc code=end

