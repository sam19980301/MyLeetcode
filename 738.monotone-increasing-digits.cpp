/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int index = s.size() - 2;
        while (index >= 0)
        {
            if (s[index] > s[index+1])
            {
                s[index]--;
                for (int i = index + 1; i < s.size(); i++)
                    s[i] = '9';
            }
            index--;
        }
        return stoi(s);
    }
};
// @lc code=end

