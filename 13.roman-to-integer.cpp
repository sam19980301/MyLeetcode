/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int curr, prev = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            char ch = *it;
            if (ch == 'I')
                curr = 1;
            else if (ch == 'V')
                curr = 5;
            else if (ch == 'X')
                curr = 10;
            else if (ch == 'L')
                curr = 50;
            else if (ch == 'C')
                curr = 100;
            else if (ch == 'D')
                curr = 500;
            else
                curr = 1000;
            
            if (curr >= prev)
                ans += curr;
            else
                ans -= curr;
            prev = curr;
        }
        return ans;
    }
};
// @lc code=end

