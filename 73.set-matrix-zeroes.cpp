/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        bool set_r1 = false, set_c1 = false;
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
                set_c1 = true;
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
                set_r1 = true;
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++)
            if (matrix[i][0] == 0)
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
        for (int j = 1; j < n; j++)
            if (matrix[0][j] == 0)
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
        if (set_r1)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        if (set_c1)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};
// @lc code=end

