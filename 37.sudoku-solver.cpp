/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool is_safe_insertion(vector<vector<char>>& board, int n, char val) {
        int r = n / 9, c = n % 9, subr = r / 3 * 3, subc = c / 3 * 3;
        for (int i = 0; i < 9; i++)
            if (board[r][i] == val || board[i][c] == val || board[subr + i / 3][subc + i % 3] == val)
                return false;
        return true;
    }

    bool solveSudoku_helper(vector<vector<char>>& board, int n) {
        if (n == 81)
            return true;
        
        int r = n / 9, c = n % 9;
        if (board[r][c] != '.')
            return solveSudoku_helper(board, n + 1);
        
        for (char ch = '1'; ch <= '9'; ch++)
        {
            if (is_safe_insertion(board, n, ch)) // is safe insertion
            {
                board[r][c] = ch;
                if (solveSudoku_helper(board, n + 1))
                    return true;
            }
        }
        board[r][c] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku_helper(board, 0);
    }
};
// @lc code=end

