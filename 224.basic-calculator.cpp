/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> ops; // monotonic ascending

        auto process_op = [&]() -> void {
            if (ops.top() == 'N')
            {
                operands.top() = -operands.top();
            }
            else
            {
                int n = operands.top();
                operands.pop();
                if (ops.top() == '+')
                    operands.top() += n;
                else
                    operands.top() -= n;
            }
            ops.pop();
        };

        bool may_be_unary = true;
        auto it = s.begin();
        while (it != s.end())
        {
            if (isspace(*it))
            {
                it++;
            }
            else if (*it == '(')
            {
                ops.push(*it++);
                may_be_unary = true;
            }
            else if (*it == ')')
            {
                while (ops.top() != '(')
                    process_op();
                ops.pop();
                it++;
                may_be_unary = false;
            }
            else if (isdigit(*it))
            {
                int n = 0;
                while (isdigit(*it))
                    n = n * 10 + (*it++ - '0');
                operands.push(n);
                may_be_unary = false;
            }
            else // operator
            {
                if (may_be_unary && *it == '-')
                    *it = 'N';
                while (!ops.empty() && (ops.top() != '(' || ops.top() == 'N'))
                    process_op();
                ops.push(*it++);
                may_be_unary = true;
            }
        }

        while (!ops.empty())
            process_op();
        return operands.top();
    }
};
// @lc code=end

