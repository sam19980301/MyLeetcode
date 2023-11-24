/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int maxAreaOfIsland_helper(vector<vector<int>>& grid, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            return 0;
        int area = 1;
        grid[r][c] = 0;
        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++)
            area += maxAreaOfIsland_helper(grid, r + DIR[i], c + DIR[i+1]);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, maxAreaOfIsland_helper(grid, i, j));
        return ans;
    }
};
// @lc code=end

