/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool is_safe_insertion(vector<vector<bool>>& board, int m, int n)
    {
        // top
        for (int i = 0; i < m; i++)
            if (board[i][n] == true)
                return false;
        
        // top left
        for (int i = 0; i < m; i++)
            if (n-m+i>=0 && board[i][n-m+i] == true)
                return false;
        
        // top right
        for (int i = 0; i < m; i++)
            if (n+m-i<board.size() && board[i][n+m-i] == true)
                return false;

        return true;
    }
    void totalNQueens_helper(vector<vector<bool>>& board, int& ans, int i)
    {
        if (i == board.size())
        {
            ans++;
            return ;
        }

        for (int j = 0; j < board.size(); j++)
        {
            if (is_safe_insertion(board, i, j))
            {
                board[i][j] = true;
                totalNQueens_helper(board, ans, i + 1);
                board[i][j] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        int ans = 0;
        totalNQueens_helper(board, ans, 0);
        return ans;
    }
};
// @lc code=end

