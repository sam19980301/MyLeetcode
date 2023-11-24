/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        auto happy_func = [](int n) -> int {
            int sum = 0;
            while (n)
            {
                int mod = n % 10;
                sum += mod * mod;
                n /= 10;
            }
            return sum;
        };
        
        n = happy_func(n);
        unordered_set<int> s;
        while (n != 1)
        {
            if (!s.insert(n).second)
                return false;
            n = happy_func(n);
        }
        return true;
    }
};
// @lc code=end

