/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        /*
            0X      ->  0 X
            1X      ->  1 X / 1X
            2X      ->  2 X / 2X    (0 <= X < 7)
            AB      ->  A B
        */
        int curr = s.back() == '0' ? 0 : 1, prev = 1;
        for (int i = s.size() - 2; i >= 0; i--)
        {
            int temp = curr;
            if (s[i] == '0')
                curr = 0;
            else if (s[i] == '1' || (s[i] == '2' && s[i+1] < '7'))
                curr += prev;
            prev = temp;
        }
        return curr;
    }
};
// @lc code=end

