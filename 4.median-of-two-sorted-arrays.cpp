/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // TODO(sam): Review twice!
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        const int s1 = static_cast<int>(nums1.size());
        const int s2 = static_cast<int>(nums2.size());
        const int sz = s1 + s2;

        // always binary search on nums1: [0, target) is at the left partition
        int lo = 0;
        int hi = static_cast<int>(nums1.size());
        while (lo <= hi)
        {
            // nums1: [0, mid1) / [mid1, nums1.size())
            // nums2: [0, mid2) / [mid2, nums2.size())
            // mid1 + mid2 = (sz + 1) / 2
            const int mid1 = lo + ((hi - lo) / 2);
            const int mid2 = ((sz + 1) / 2) - mid1;

            const int l1 = (mid1 >= 1) ? nums1.at(mid1 - 1) : numeric_limits<int>::min();
            const int r1 = (mid1 < s1) ? nums1.at(mid1) : numeric_limits<int>::max();
            const int l2 = (mid2 >= 1) ? nums2.at(mid2 - 1) : numeric_limits<int>::min();
            const int r2 = (mid2 < s2) ? nums2.at(mid2) : numeric_limits<int>::max();

            if (l1 > r2)
            {
                hi = mid1 - 1;
            }
            else if (l2 > r1)
            {
                lo = mid1 + 1;
            }
            else
            {
                if (sz % 2)
                {
                    return max(l1, l2);
                }
                return static_cast<double>(max(l1, l2) + min(r1, r2)) / 2;
            }
        }
        return numeric_limits<int>::min();
    }
};
// @lc code=end
