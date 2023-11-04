/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l < h)
        {
            int m = l + (h - l) / 2;
            if (!isBadVersion(m))
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
};
// @lc code=end

