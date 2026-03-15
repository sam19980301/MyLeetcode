/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        const size_t n = matrix.size();
        ranges::reverse(matrix);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i + 1; j < n; j++)
            {
                swap(matrix.at(i).at(j), matrix.at(j).at(i));
            }
        }

        /*
        const size_t n = matrix.size();
        for (size_t i = 0; i < n / 2; i++)
        {
            const size_t row_0 = i;
            size_t col_0 = i;
            size_t row_1 = i;
            const size_t col_1 = n - i - 1;
            const size_t row_2 = n - i - 1;
            size_t col_2 = n - i - 1;
            size_t row_3 = n - i - 1;
            const size_t col_3 = i;

            while (col_0 < col_1)
            {
                swap(matrix.at(row_0).at(col_0), matrix.at(row_1).at(col_1));
                swap(matrix.at(row_0).at(col_0), matrix.at(row_2).at(col_2));
                swap(matrix.at(row_0).at(col_0), matrix.at(row_3).at(col_3));
                col_0++;
                row_1++;
                col_2--;
                row_3--;
            }
        }
        */
    }
};
// @lc code=end
