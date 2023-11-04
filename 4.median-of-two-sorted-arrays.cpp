/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int findMedianSortedArrays_helper(
        vector<int>::iterator b1,
        vector<int>::iterator e1,
        vector<int>::iterator b2,
        vector<int>::iterator e2,
        int n
    ) {
        if (b1 == e1)
            return *(b2 + n);
        if (b2 == e2)
            return *(b1 + n);
        
        // lower mid
        int offset1 = (e1 - b1 - 1) / 2, offset2 = (e2 - b2 - 1) / 2;
        auto m1 = b1 + offset1, m2 = b2 + offset2;

        if (n > offset1 + offset2)
        {
            if (*m1 < *m2)
            {
                n -= offset1 + 1;
                b1 = m1 + 1;
            }
            else
            {
                n -= offset2 + 1;
                b2 = m2 + 1;
            }
        }
        else
        {
            if (*m1 < *m2)
                e2 = m2;
            else
                e1 = m1;
        }
        return findMedianSortedArrays_helper(b1, e1, b2, e2, n);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        auto b1 = nums1.begin();
        auto e1 = nums1.end();
        auto b2 = nums2.begin();
        auto e2 = nums2.end();
        double n = findMedianSortedArrays_helper(b1, e1, b2, e2, (size - 1) / 2);
        if (size % 2 == 0)
            n = (n + findMedianSortedArrays_helper(b1, e1, b2, e2, size / 2)) / 2;
        return n;
    }
};
// @lc code=end

