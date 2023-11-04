/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = 0;
        stack<int> s;
        for (string& token : tokens)
        {
            if (token == "+")
            {
                n = s.top() + n;
                s.pop();
            }
            else if (token == "-")
            {
                n = s.top() - n;
                s.pop();
            }
            else if (token == "*")
            {
                n = s.top() * n;
                s.pop();
            }
            else if (token == "/")
            {
                n = s.top() / n;
                s.pop();
            }
            else
            {
                s.push(n);
                n = 0;
                int sign = 1;
                auto it = token.begin();
                if (!isdigit(*it))
                {
                    if (*it == '-')
                        sign = -1;
                    it++;
                }
                while (it != token.end())
                {
                    n = n * 10 + *it - '0';
                    it++;
                }
                n *= sign;
                // n = stoi(token);
            }
        }
        return n;
    }
};
// @lc code=end

