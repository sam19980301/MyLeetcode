/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), size = m * n;
        int lo = 0, hi = size - 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid/n][mid%n] < target)
                lo = mid + 1;
            else
                hi = mid;

        }
        return (matrix[lo/n][lo%n] == target);
    }
};
// @lc code=end

