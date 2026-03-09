/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr size_t sub_sz = 3;
    static constexpr size_t sz = sub_sz * sub_sz;

  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        array<bool, sz> filled_arr{};
        auto is_valid = [&](const size_t i, const size_t j) -> bool {
            auto ch = board.at(i).at(j);
            if (ch == '.')
            {
                return true;
            }
            auto &filled = filled_arr.at(ch - '1');
            // equivalent to !exchange(filled, true);
            if (filled)
            {
                return false;
            }
            filled = true;
            return true;
        };

        // row
        for (size_t i = 0; i < sz; i++)
        {
            filled_arr.fill(false);
            for (size_t j = 0; j < sz; j++)
            {
                if (!is_valid(i, j))
                {
                    return false;
                }
            }
        }

        // column
        for (size_t j = 0; j < sz; j++)
        {
            filled_arr.fill(false);
            for (size_t i = 0; i < sz; i++)
            {
                if (!is_valid(i, j))
                {
                    return false;
                }
            }
        }

        // sub-boxes
        for (size_t box = 0; box < sz; box++)
        {
            filled_arr.fill(false);
            for (size_t n = 0; n < sz; n++)
            {
                const size_t i = (box / sub_sz * sub_sz) + (n / sub_sz);
                const size_t j = (box % sub_sz * sub_sz) + (n % sub_sz);
                if (!is_valid(i, j))
                {
                    return false;
                }
            }
        }

        return true;
    }
};
// @lc code=end
