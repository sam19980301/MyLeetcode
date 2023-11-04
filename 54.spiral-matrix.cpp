/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int x = 0, y = 0, row_step = matrix.size() - 1, col_step = matrix[0].size() - 1;
        while (row_step > 0 && col_step > 0) // four-direction
        {
            for (int i = 0; i < col_step; i++)
                ans.push_back(matrix[x][y++]);
            for (int i = 0; i < row_step; i++)
                ans.push_back(matrix[x++][y]);
            for (int i = 0; i < col_step; i++)
                ans.push_back(matrix[x][y--]);
            for (int i = 0; i < row_step; i++)
                ans.push_back(matrix[x--][y]);
            x++;
            y++;
            row_step -= 2;
            col_step -= 2;
        }
        
        if (row_step < 0 || col_step < 0)
            return ans;
        
        while (col_step--)
            ans.push_back(matrix[x][y++]);
        while (row_step--)
            ans.push_back(matrix[x++][y]);
        ans.push_back(matrix[x][y]);
        return ans;
    }
};
// @lc code=end

