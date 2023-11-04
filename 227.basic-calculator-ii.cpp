/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        // Notes (expression parsing reference): https://cp-algorithms.com/string/expression_parsing.html
        stack<int> operands;    // stack for operand
        stack<char> ops;        // stack for operator (monotonic ascending)

        auto process_op = [&]() -> void {
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            if (ops.top() == '+')
                operands.push(a + b);
            else if (ops.top() == '-')
                operands.push(a - b);
            else if (ops.top() == '*')
                operands.push(a * b);
            else
                operands.push(a / b);
            ops.pop();
        };

        auto it = s.begin();
        while (it != s.end())
        {
            if (isspace(*it))
            {
                it++;
            }
            else if (isdigit(*it))
            {
                int n = 0;
                while (isdigit(*it))
                    n = n * 10 + (*it++ - '0');
                operands.push(n);
            }
            else // operator
            {
                // maintain monotonicity
                while (!ops.empty() && (ops.top() == '*' || ops.top() == '/' || *it == '+' || *it == '-'))
                    process_op();
                ops.push(*it++);
            }
        }

        while (!ops.empty())
            process_op();

        return operands.top();
    }
};
// @lc code=end