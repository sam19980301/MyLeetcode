/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        n -= 2;
        int prev = 1, curr = 2;
        while (n--)
        {
            int next = curr + prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
// @lc code=end

