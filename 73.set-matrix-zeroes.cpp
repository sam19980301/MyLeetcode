/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void setZeroes(vector<vector<int>> &matrix) // NOLINT(readability-function-cognitive-complexity)
    {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        bool set_first_row = false;
        for (size_t j = 0; j < n; j++)
        {
            if (!matrix.at(0).at(j))
            {
                set_first_row = true;
            }
        }
        bool set_first_col = false;
        for (size_t i = 0; i < m; i++)
        {
            if (!matrix.at(i).at(0))
            {
                set_first_col = true;
            }
        }

        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                if (!matrix.at(i).at(j))
                {
                    matrix.at(i).at(0) = 0;
                    matrix.at(0).at(j) = 0;
                }
            }
        }

        for (size_t j = 1; j < n; j++)
        {
            if (!matrix.at(0).at(j))
            {
                for (size_t i = 0; i < m; i++)
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }

        for (size_t i = 1; i < m; i++)
        {
            if (!matrix.at(i).at(0))
            {
                for (size_t j = 0; j < n; j++)
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }

        /*
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                if (!matrix.at(i).at(0) || !matrix.at(0).at(j))
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }
        */

        if (set_first_row)
        {
            for (size_t j = 0; j < n; j++)
            {
                matrix.at(0).at(j) = 0;
            }
        }

        if (set_first_col)
        {
            for (size_t i = 0; i < m; i++)
            {
                matrix.at(i).at(0) = 0;
            }
        }

        /*
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        vector<bool> r_is_zeros(m);
        vector<bool> c_is_zeros(n);
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (!matrix.at(i).at(j))
                {
                    r_is_zeros.at(i) = true;
                    c_is_zeros.at(j) = true;
                }
            }
        }

        for (size_t i = 0; i < m; i++)
        {
            if (r_is_zeros.at(i))
            {
                for (size_t j = 0; j < n; j++)
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }

        for (size_t j = 0; j < n; j++)
        {
            if (c_is_zeros.at(j))
            {
                for (size_t i = 0; i < m; i++)
                {
                    matrix.at(i).at(j) = 0;
                }
            }
        }
        */
    }
};
// @lc code=end
