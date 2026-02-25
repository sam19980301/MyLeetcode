/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> s;
        for (auto &token : tokens)
        {
            if (token == "+")
            {
                const int rhs = s.top();
                s.pop();
                s.top() += rhs;
            }
            else if (token == "-")
            {
                const int rhs = s.top();
                s.pop();
                s.top() -= rhs;
            }
            else if (token == "*")
            {
                const int rhs = s.top();
                s.pop();
                s.top() *= rhs;
            }
            else if (token == "/")
            {
                const int rhs = s.top();
                s.pop();
                s.top() /= rhs;
            }
            else
            {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
// @lc code=end
