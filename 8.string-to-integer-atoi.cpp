/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        bool pos = true;
        int n = 0;

        auto it = s.begin();
        while (it != s.end() && isspace(*it))
            it++;
        
        if (it != s.end() && *it == '+')
            it++;
        else if (it != s.end() && *it == '-')
        {
            pos = false;
            it++;
        }

        while (it != s.end() && isdigit(*it))
        {
            int digit = *it++ - '0';
            if ((INT_MIN + pos + digit) / 10 > n)
                return pos ? INT_MAX : INT_MIN;
            n = 10 * n - digit;
        }
        return pos ? -n : n;
    }
};
// @lc code=end

