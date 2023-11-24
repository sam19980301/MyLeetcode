/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void solve_helper(vector<vector<char>>& board, int i, int j)
    {
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
            return ;

        board[i][j] = '#';
        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int k = 0; k < 4; k++)
            solve_helper(board, i + DIR[k], j + DIR[k+1]);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            solve_helper(board, i, 0);
            solve_helper(board, i, n - 1);
        }
        for (int j = 1; j < n - 1; j++)
        {
            solve_helper(board, 0, j);
            solve_helper(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end

