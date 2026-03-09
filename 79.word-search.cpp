/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};

    bool exist_helper(int i, int j, string::iterator it, string::iterator ed_it, vector<vector<char>> &board)
    {
        if (it == ed_it)
        {
            return true;
        }

        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board.front().size());
        if (i < 0 || i >= m || j < 0 || j >= n || board.at(i).at(j) != *it)
        {
            return false;
        }

        auto &ch = board.at(i).at(j);
        ch = 0;
        for (auto [dr, dc] : dirs)
        {
            if (exist_helper(i + dr, j + dc, it + 1, ed_it, board))
            {
                return true;
            }
        }
        ch = *it;
        return false;
    }

  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        const int m = static_cast<int>(board.size());
        const int n = static_cast<int>(board.front().size());
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (exist_helper(i, j, word.begin(), word.end(), board))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
// @lc code=end
