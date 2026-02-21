/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);

#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int firstBadVersion(int n)
    {
        int lo = 0;
        int hi = n;
        while (lo < hi)
        {
            const int mid = lo + ((hi - lo) / 2);
            if (isBadVersion(mid))
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
// @lc code=end
