/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int n_land = 0, n_connected = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    n_land++;
                    if (i > 0 && grid[i-1][j] == 1)
                        n_connected++;
                    if (j > 0 && grid[i][j-1] == 1)
                        n_connected++;
                }
            }
        }
        return 4 * n_land - 2 * n_connected;
    }
};
// @lc code=end

