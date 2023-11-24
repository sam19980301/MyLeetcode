/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool closedIsland_helper(vector<vector<int>>& grid, int r, int c, int filled_value)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 0)
            return false;
        
        // grid[r][c] == 0
        grid[r][c] = filled_value;
        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++)
            closedIsland_helper(grid, r + DIR[i], c + DIR[i+1], filled_value);
        return true;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        /*
            0 : closed island
            1 : water
            2 : open island
        */
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            closedIsland_helper(grid, i, 0, 2);
            closedIsland_helper(grid, i, n - 1, 2);
        }
        for (int j = 0; j < n; j++)
        {
            closedIsland_helper(grid, 0, j, 2);
            closedIsland_helper(grid, m - 1, j, 2);
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (closedIsland_helper(grid, i, j, 1))
                    ans++;
        return ans;
    }
};
// @lc code=end

