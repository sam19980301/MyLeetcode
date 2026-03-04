/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};
    void numIslands_helper(int r, int c, vector<vector<char>> &grid)
    {
        auto m = grid.size();
        auto n = grid.front().size();
        if (r < 0 || cmp_greater_equal(r, m) || c < 0 || cmp_greater_equal(c, n))
        {
            return;
        }

        char &ch = grid.at(r).at(c);
        if (ch == '0')
        {
            return;
        }
        ch = '0';

        for (auto [dr, dc] : dirs)
        {
            numIslands_helper(r + dr, c + dc, grid);
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid)
    {
        auto m = grid.size();
        auto n = grid.front().size();
        int ans = 0;
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                auto &ch = grid.at(i).at(j);
                if (ch == '1')
                {
                    ans++;
                }
                numIslands_helper(static_cast<int>(i), static_cast<int>(j), grid);
            }
        }
        return ans;
    }
};
// @lc code=end
