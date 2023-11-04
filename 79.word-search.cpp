/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int DIR[5];
    bool exist_helper(vector<vector<char>>& board, string& word, int i, int j, int k) {
        int m = board.size(), n = board[0].size();
        if (k == word.size())
            return true;
        if (i<0 || i>=m || j<0 || j>=n || board[i][j] != word[k])
            return false;
        board[i][j] = ' ';
        for (int l = 0; l < 4; l++)
            if (exist_helper(board, word, i+DIR[l], j+DIR[l+1], k+1))
                return true;
        board[i][j] = word[k];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (exist_helper(board, word, i, j, 0))
                    return true;
        return false;
    }
};
const int Solution::DIR[5] = { 0, 1, 0, -1, 0 };
// @lc code=end

