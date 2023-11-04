/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int n = x, rn = 0;
        while (n)
        {
            int remainder = n % 10;
            if (rn > (INT_MAX - remainder) / 10)
                return false;
            rn = rn * 10 + n % 10;
            n /= 10;
        }
        return x == rn;
    }
};
// @lc code=end

