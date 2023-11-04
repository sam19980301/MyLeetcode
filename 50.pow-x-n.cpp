/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 | x == 1)
            return x;
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / x / myPow(x, -(n+1));
        return (n % 2 ? x : 1) * myPow(x * x, n / 2);
    }
};
// @lc code=end

