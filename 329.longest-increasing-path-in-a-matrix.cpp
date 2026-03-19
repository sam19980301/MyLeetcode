/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};
    int &longestIncreasingPath_helper(int r, int c, vector<vector<int>> &matrix, vector<vector<int>> &lip_matrix)
    {
        int &lip_curr = lip_matrix.at(r).at(c);
        if (lip_curr > 0)
        {
            return lip_curr;
        }

        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix.front().size());

        const int value = matrix.at(r).at(c);
        lip_curr = 1;
        for (auto [dr, dc] : dirs)
        {
            const int nr = r + dr;
            const int nc = c + dc;
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || value >= matrix.at(nr).at(nc))
            {
                continue;
            }
            lip_curr = max(lip_curr, 1 + longestIncreasingPath_helper(nr, nc, matrix, lip_matrix));
        }
        return lip_curr;
    }

  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix.front().size());
        vector<vector<int>> lip_matrix(m, vector<int>(n));
        int ans = 0;
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                ans = max(ans, longestIncreasingPath_helper(r, c, matrix, lip_matrix));
            }
        }
        return ans;
    }
};
// @lc code=end
