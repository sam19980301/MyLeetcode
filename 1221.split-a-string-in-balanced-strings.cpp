/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, rcnt = 0;
        for (char ch : s)
        {
            if (ch == 'R')
                rcnt++;
            else
                rcnt--;
            if (rcnt == 0)
                ans++;
        }
        return ans;
    }
};
// @lc code=end

