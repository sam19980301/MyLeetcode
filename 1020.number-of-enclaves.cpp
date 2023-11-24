/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void numEnclaves_helper(vector<vector<int>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return ;
        
        // grid[r][c] == 1
        grid[r][c] = 0;
        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++)
            numEnclaves_helper(grid, r + DIR[i], c + DIR[i+1]);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            numEnclaves_helper(grid, i, 0);
            numEnclaves_helper(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            numEnclaves_helper(grid, 0, j);
            numEnclaves_helper(grid, m - 1, j);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    ans++;
        return ans;
    }
};
// @lc code=end

