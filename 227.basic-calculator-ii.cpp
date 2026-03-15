/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int calculate(string s) // NOLINT(readability-function-cognitive-complexity)
    {
        // build Reverse Polish Notation (RPN)
        auto isop = [](const char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/'; };

        auto priority = [](const char op) {
            if (op == '+' || op == '-')
            {
                return 1;
            }
            if (op == '*' || op == '/')
            {
                return 2;
            }
            return -1;
        };

        auto process_op = [](stack<int> &s, const char op) {
            const int rhs = s.top();
            s.pop();
            const int lhs = s.top();
            s.pop();
            if (op == '+')
            {
                s.push(lhs + rhs);
            }
            else if (op == '-')
            {
                s.push(lhs - rhs);
            }
            else if (op == '*')
            {
                s.push(lhs * rhs);
            }
            else if (op == '/')
            {
                s.push(lhs / rhs);
            }
        };

        stack<int> s_num;
        stack<char> s_op;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (isspace(*it))
            {
            }
            else if (isop(*it))
            {
                while (!s_op.empty() && priority(s_op.top()) >= priority(*it)) // left associativity
                {
                    process_op(s_num, s_op.top());
                    s_op.pop();
                }
                s_op.push(*it);
            }
            else // isdigit(ch)
            {
                int n = 0;
                while (it != s.end() && isdigit(*it))
                {
                    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                    n = (n * 10) + (*it++ - '0');
                }
                it--;
                s_num.push(n);
            }
        }

        while (!s_op.empty())
        {
            process_op(s_num, s_op.top());
            s_op.pop();
        }
        return s_num.top();
    }
};
// @lc code=end
