/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        const size_t m = matrix.size();
        const size_t n = matrix.front().size();

        int len = 0;
        vector<int> dp_prev(n);
        for (size_t i = 0; i < m; i++)
        {
            vector<int> dp_curr(n);
            for (size_t j = 0; j < n; j++)
            {
                if (matrix.at(i).at(j) == '1')
                {
                    int &val = dp_curr.at(j);
                    val = 1 + min({dp_prev.at(j), j > 0 ? dp_curr.at(j - 1) : 0, j > 0 ? dp_prev.at(j - 1) : 0});
                    len = max(len, val);
                }
            }
            dp_prev.swap(dp_curr);
        }
        return len * len;
    }
};
// @lc code=end
