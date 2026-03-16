/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int calculate(string s) // NOLINT(readability-function-cognitive-complexity)
    {
        // TODO(sam): Review
        // build Reverse Polish Notation (RPN)
        auto isop = [](const char ch) { return ch == '+' || ch == '-' || ch == '*' || ch == '/'; };

        auto is_unary = [](const char ch) { return ch == '-'; };

        auto priority = [](const char op) {
            if (op < 0) // unary operator
            {
                return 3;
            }
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

        auto process_op = [](stack<int64_t> &s, const char op) {
            if (op < 0) // unary operator
            {
                s.top() = -s.top();
                return;
            }

            auto rhs = s.top();
            s.pop();
            auto lhs = s.top();
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

        bool may_be_unary = true;
        stack<int64_t> s_num;
        stack<signed char> s_op;
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (isspace(*it))
            {
            }
            else if (*it == '(')
            {
                s_op.push(*it);
                may_be_unary = true;
            }
            else if (*it == ')')
            {
                while (s_op.top() != '(')
                {
                    process_op(s_num, s_op.top());
                    s_op.pop();
                }
                s_op.pop();
                may_be_unary = false;
            }
            else if (isop(*it))
            {
                if (may_be_unary && is_unary(*it))
                {
                    *it = static_cast<signed char>(-*it);
                }
                while (!s_op.empty() && priority(s_op.top()) >= priority(*it))
                {
                    process_op(s_num, s_op.top());
                    s_op.pop();
                }
                s_op.push(*it);
                may_be_unary = true;
            }
            else // isdigit(*it)
            {
                int64_t n = 0;
                while (it != s.end() && isdigit(*it))
                {
                    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                    n = (n * 10) + (*it++ - '0');
                }
                it--;
                s_num.push(n);
                may_be_unary = false;
            }
        }

        while (!s_op.empty())
        {
            process_op(s_num, s_op.top());
            s_op.pop();
        }
        return static_cast<int>(s_num.top());
    }
};
// @lc code=end
