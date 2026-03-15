/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        auto ub_r_it = ranges::upper_bound(matrix, target, less<>(), [](auto &vec) { return vec.front(); });
        if (ub_r_it == matrix.begin())
        {
            return false;
        }
        vector<int> &vec = *(ub_r_it - 1);
        // return ranges::binary_search(vec, target, less<>());
        auto lb_c_it = ranges::lower_bound(vec, target, less<>());
        return lb_c_it != vec.end() && *lb_c_it == target;

        /*
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        // upper bound
        size_t lo_row = 0;
        size_t hi_row = m;
        while (lo_row < hi_row)
        {
            const size_t mid_row = lo_row + ((hi_row - lo_row) / 2);
            if (matrix.at(mid_row).front() <= target)
            {
                lo_row = mid_row + 1;
            }
            else
            {
                hi_row = mid_row;
            }
        }
        if (lo_row == 0)
        {
            return false;
        }

        // lower bound
        vector<int> &vec = matrix.at(lo_row - 1);
        size_t lo_col = 0;
        size_t hi_col = n;
        while (lo_col < hi_col)
        {
            const size_t mid_col = lo_col + ((hi_col - lo_col) / 2);
            if (vec.at(mid_col) < target)
            {
                lo_col = mid_col + 1;
            }
            else
            {
                hi_col = mid_col;
            }
        }
        return (lo_col != n) && vec.at(lo_col) == target;
        */
    }
};
// @lc code=end
