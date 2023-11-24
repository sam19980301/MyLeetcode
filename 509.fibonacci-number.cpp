/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n < 2)
            return n;
        int curr = 1, prev = 0;
        for (int i = 1; i < n; i++)
        {
            int next = curr + prev;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
// @lc code=end

