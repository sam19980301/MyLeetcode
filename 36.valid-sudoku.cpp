/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                if (board[r][c] == '.')
                    continue;
                
                // check row
                for (int i = c+1; i < 9; i++)
                    if (board[r][c] == board[r][i])
                        return false;
                
                // check col
                for (int i = r+1; i < 9; i++)
                    if (board[r][c] == board[i][c])
                        return false;
                
                // check subgrid
                int subr = r/3*3, subc = c/3*3;
                for (int i = r%3*3+c%3+1; i < 9; i++)
                    if (board[r][c] == board[subr+i/3][subc+i%3])
                        return false;   
            }
        }
        return true;
    }
};
// @lc code=end

