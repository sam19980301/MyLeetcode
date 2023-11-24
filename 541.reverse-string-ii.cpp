/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        auto it = s.begin();
        while (it <= s.end())
        {
            reverse(it, min(it + k, s.end()));
            it += 2 * k;
        }
        return s;
    }
};
// @lc code=end

