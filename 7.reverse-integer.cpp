/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        // range [-2147483648, 2147483647]
        int n = 0;
        while (x)
        {
            if (x > 0 && n > (INT_MAX - x % 10) / 10)
                return 0;
            if (x < 0 && n < (INT_MIN - x % 10) / 10)
                return 0;
            n = n * 10 + x % 10;
            x /= 10;
        }
        return n;
    }
};
// @lc code=end

