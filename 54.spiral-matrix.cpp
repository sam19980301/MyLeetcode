/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    enum class State : uint8_t
    {
        kRight,
        kDown,
        kLeft,
        kUp,
    };

  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int st_row = 0;
        int ed_row = static_cast<int>(matrix.size()) - 1;
        int st_col = 0;
        int ed_col = static_cast<int>(matrix.front().size()) - 1;

        State direction = State::kRight;
        while (st_row <= ed_row && st_col <= ed_col)
        {
            if (direction == State::kRight)
            {
                for (int col = st_col; col <= ed_col; col++)
                {
                    ans.push_back(matrix.at(st_row).at(col));
                }
                st_row++;
                direction = State::kDown;
            }
            else if (direction == State::kDown)
            {
                for (int row = st_row; row <= ed_row; row++)
                {
                    ans.push_back(matrix.at(row).at(ed_col));
                }
                ed_col--;
                direction = State::kLeft;
            }
            else if (direction == State::kLeft)
            {
                for (int col = ed_col; col >= st_col; col--)
                {
                    ans.push_back(matrix.at(ed_row).at(col));
                }
                ed_row--;
                direction = State::kUp;
            }
            else if (direction == State::kUp)
            {
                for (int row = ed_row; row >= st_row; row--)
                {
                    ans.push_back(matrix.at(row).at(st_col));
                }
                st_col++;
                direction = State::kRight;
            }
        }
        return ans;

        /*
        vector<int> ans;
        const int m = static_cast<int>(matrix.size());
        const int n = static_cast<int>(matrix.front().size());

        int x = 0;
        int y = 0;
        int h_step = m - 1;
        int w_step = n - 1;
        while (h_step > 0 && w_step > 0)
        {
            // right
            for (int i = 0; i < w_step; i++)
            {
                ans.push_back(matrix.at(y).at(x++));
            }
            // downward
            for (int i = 0; i < h_step; i++)
            {
                ans.push_back(matrix.at(y++).at(x));
            }
            // left
            for (int i = 0; i < w_step; i++)
            {
                ans.push_back(matrix.at(y).at(x--));
            }
            // upward
            for (int i = 0; i < h_step; i++)
            {
                ans.push_back(matrix.at(y--).at(x));
            }

            x++;
            y++;
            w_step -= 2;
            h_step -= 2;
        }

        if (w_step < 0 || h_step < 0)
        {
            return ans;
        }
        // right
        for (int i = 0; i < w_step; i++)
        {
            ans.push_back(matrix.at(y).at(x++));
        }
        // downward
        for (int i = 0; i < h_step; i++)
        {
            ans.push_back(matrix.at(y++).at(x));
        }
        ans.push_back(matrix.at(y).at(x));
        return ans;
        */
    }
};
// @lc code=end
