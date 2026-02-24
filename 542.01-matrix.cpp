/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    template <typename T> using Array = vector<T>;
    template <typename T> using Matrix = vector<vector<T>>;
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};

  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        // TODO(sam): Review
        auto m = mat.size();
        auto n = mat.front().size();
        Matrix<int> ans(m, Array<int>(n, numeric_limits<int>::max()));

        queue<pair<int, int>> q; // coordinate
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (!mat.at(i).at(j))
                {
                    q.emplace(i, j);
                    ans.at(i).at(j) = 0;
                }
            }
        }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            const int curr_dist = ans.at(i).at(j) + 1;
            for (auto [dr, dc] : dirs)
            {
                const int r = i + dr;
                const int c = j + dc;
                if (r < 0 || cmp_greater_equal(r, m) || c < 0 || cmp_greater_equal(c, n))
                {
                    continue;
                }
                int &best_dist = ans.at(r).at(c);
                if (curr_dist < best_dist)
                {
                    best_dist = curr_dist;
                    q.emplace(r, c);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
