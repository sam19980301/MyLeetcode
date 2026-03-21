/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    void solveNQueens_helper(int row, vector<string> &board, vector<vector<string>> &ans)
    {
        const int n = static_cast<int>(board.size());
        if (n == row)
        {
            ans.push_back(board);
        }

        auto is_valid = [&n, &board](int row, int col) {
            for (int i = 0; i < row; i++)
            {
                if (board.at(i).at(col) == 'Q')
                {
                    return false;
                }
            }

            for (int k = 1; row >= k && col >= k; k++)
            {
                if (board.at(row - k).at(col - k) == 'Q')
                {
                    return false;
                }
            }

            for (int k = 1; row >= k && col + k < n; k++)
            {
                if (board.at(row - k).at(col + k) == 'Q')
                {
                    return false;
                }
            }
            return true;
        };

        for (int col = 0; col < n; col++)
        {
            if (!is_valid(row, col))
            {
                continue;
            }

            board.at(row).at(col) = 'Q';
            solveNQueens_helper(row + 1, board, ans);
            board.at(row).at(col) = '.';
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solveNQueens_helper(0, board, ans);
        return ans;
    }
};
// @lc code=end
