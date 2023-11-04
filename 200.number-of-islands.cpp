/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int DIR[5];
    void numIslands_helper(vector<vector<char>>& grid, int i, int j){ // dfs
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
            return ;
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++)
            numIslands_helper(grid, i+DIR[k], j+DIR[k+1]);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                    ans++;
                numIslands_helper(grid, i, j);
            }
        }
        return ans;
    }
};
const int Solution::DIR[5] = { 0, 1, 0, -1, 0 };
// @lc code=end

