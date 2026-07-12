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
        const int m = static_cast<int>(mat.size());
        const int n = static_cast<int>(mat.front().size());
        Matrix<int> ans(m, Array<int>(n, numeric_limits<int>::max()));

        queue<pair<int, int>> q; // coordinate
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!mat.at(i).at(j))
                {
                    q.emplace(i, j);
                    ans.at(i).at(j) = 0;
                }
            }
        }

        int curr_dist = 0;
        while (!q.empty())
        {
            curr_dist++;
            auto qs = q.size();
            while (qs--)
            {
                auto [i, j] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs)
                {
                    const int r = i + dr;
                    const int c = j + dc;
                    if (r < 0 || r >= m || c < 0 || c >= n)
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
        }
        return ans;
    }
};
// @lc code=end
