/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class NumMatrix
{
  private:
    vector<vector<int>> sum_matrix;

  public:
    explicit NumMatrix(vector<vector<int>> &matrix) : sum_matrix(matrix)
    {
        const size_t m = sum_matrix.size();
        const size_t n = sum_matrix.front().size();

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                int &sum = sum_matrix.at(i).at(j);
                sum += (i > 0) ? sum_matrix.at(i - 1).at(j) : 0;
                sum += (j > 0) ? sum_matrix.at(i).at(j - 1) : 0;
                sum -= (i > 0 && j > 0) ? sum_matrix.at(i - 1).at(j - 1) : 0;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = sum_matrix.at(row2).at(col2);
        sum -= (row1 > 0) ? sum_matrix.at(row1 - 1).at(col2) : 0;
        sum -= (col1 > 0) ? sum_matrix.at(row2).at(col1 - 1) : 0;
        sum += (row1 > 0 && col1 > 0) ? sum_matrix.at(row1 - 1).at(col1 - 1) : 0;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
