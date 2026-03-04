/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};
    static constexpr int kEmpty = 0;
    static constexpr int kFresh = 1;
    static constexpr int kRotten = 2;

  public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int fresh_cnt = 0;

        const size_t m = grid.size();
        const size_t n = grid.front().size();
        queue<pair<int, int>> q; // coordinate
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                const int &val = grid.at(i).at(j);
                if (val == kFresh)
                {
                    fresh_cnt++;
                }
                else if (val == kRotten)
                {
                    q.emplace(i, j);
                }
            }
        }

        int time = 0;
        while (!q.empty() && fresh_cnt)
        {
            auto qs = q.size();
            while (qs--)
            {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs)
                {
                    const int r = i + dr;
                    const int c = j + dc;
                    if (r < 0 || cmp_greater_equal(r, m) || c < 0 || cmp_greater_equal(c, n))
                    {
                        continue;
                    }
                    int &val = grid.at(r).at(c);
                    if (val == kFresh)
                    {
                        q.emplace(r, c);
                        fresh_cnt--;
                        val = kRotten;
                    }
                }
            }
            time++;
        }
        return fresh_cnt ? -1 : time;
    }
};
// @lc code=end
