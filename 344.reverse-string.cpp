/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        // reverse(s.begin(), s.end());
        int lo = 0, hi = s.size() - 1;
        while (lo < hi)
            swap(s[lo++], s[hi--]);
    }
};
// @lc code=end

