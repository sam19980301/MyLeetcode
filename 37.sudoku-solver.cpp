/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t box_sz = 3;
    static constexpr size_t line_sz = box_sz * box_sz;
    static constexpr size_t grid_sz = line_sz * line_sz;
    static constexpr char kEMPTY = '.';

    bool solveSudoku_helper(size_t idx, vector<vector<char>> &board)
    {
        if (idx == grid_sz)
        {
            return true;
        }

        const size_t r = idx / line_sz;
        const size_t c = idx % line_sz;

        auto is_valid = [&board](const size_t r, const size_t c, const char ch) {
            for (size_t n = 0; n < line_sz; n++)
            {
                if (board.at(r).at(n) == ch || board.at(n).at(c) == ch ||
                    board.at((r / box_sz * box_sz) + (n / box_sz)).at((c / box_sz * box_sz) + (n % box_sz)) == ch)
                {
                    return false;
                }
            }
            return true;
        };

        char &ch = board.at(r).at(c);
        if (ch != kEMPTY)
        {
            return solveSudoku_helper(idx + 1, board);
        }

        for (char attempt_ch = '1'; attempt_ch <= '9'; attempt_ch++)
        {
            if (!is_valid(r, c, attempt_ch))
            {
                continue;
            }
            ch = attempt_ch;
            if (solveSudoku_helper(idx + 1, board))
            {
                return true;
            }
            ch = kEMPTY;
        }
        return false;
    }

  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solveSudoku_helper(0, board);
    }
};
// @lc code=end
