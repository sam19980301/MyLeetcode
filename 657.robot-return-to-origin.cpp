/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int h = 0, v = 0;
        for (char ch : moves)
        {
            if (ch == 'U')
                v++;
            else if (ch == 'D')
                v--;
            else if (ch == 'R')
                h++;
            else
                h--;
        }
        return (h == 0) && (v == 0);
    }
};
// @lc code=end

