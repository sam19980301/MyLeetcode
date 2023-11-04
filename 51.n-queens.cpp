/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool is_valid_insertion(vector<string>& board, int m, int n) {
        for (int i = 0; i < m; i++) // top
            if (board[i][n] == 'Q')
                return false;
        
        for (int i = 0; i < m; i++) // top left
            if (n-m+i >= 0 && board[i][n-m+i] == 'Q')
                return false;
        
        for (int i = 0; i < m; i++)
            if (n+m-i < board.size() && board[i][n+m-i] == 'Q')
                return false;
        
        return true;
    }

    void solveNQueens_helper(vector<string>& board, vector<vector<string>>& ans, int i) {
        if (i == board.size())
        {
            ans.push_back(board);
            return ;
        }

        for (int j = 0; j < board.size(); j++)
        {
            if (is_valid_insertion(board, i, j))
            {
                board[i][j] = 'Q';
                solveNQueens_helper(board, ans, i + 1);
                board[i][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solveNQueens_helper(board, ans, 0);
        return ans;
    }
};
// @lc code=end

