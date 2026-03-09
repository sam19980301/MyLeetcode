/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};

    void pacificAtlantic_helper(int i, int j, int prev_height, vector<vector<bool>> &reachables,
                                vector<vector<int>> &heights)
    {
        const int m = static_cast<int>(heights.size());
        const int n = static_cast<int>(heights.front().size());

        if (i < 0 || i >= m || j < 0 || j >= n || reachables.at(i).at(j))
        {
            return;
        }

        const int curr_height = heights.at(i).at(j);
        if (curr_height < prev_height)
        {
            return;
        }

        reachables.at(i).at(j) = true;
        for (auto [dr, dc] : dirs)
        {
            pacificAtlantic_helper(i + dr, j + dc, curr_height, reachables, heights);
        }
    }

  public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        const int m = static_cast<int>(heights.size());
        const int n = static_cast<int>(heights.front().size());

        vector<vector<bool>> p_reachables(m, vector<bool>(n));
        for (int j = 0; j < n; j++)
        {
            pacificAtlantic_helper(0, j, 0, p_reachables, heights);
        }
        for (int i = 0; i < m; i++)
        {
            pacificAtlantic_helper(i, 0, 0, p_reachables, heights);
        }

        vector<vector<bool>> a_reachables(m, vector<bool>(n));
        for (int j = 0; j < n; j++)
        {
            pacificAtlantic_helper(m - 1, j, 0, a_reachables, heights);
        }
        for (int i = 0; i < m; i++)
        {
            pacificAtlantic_helper(i, n - 1, 0, a_reachables, heights);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p_reachables.at(i).at(j) && a_reachables.at(i).at(j))
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
// @lc code=end
