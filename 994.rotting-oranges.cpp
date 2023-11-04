/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int DIR[5];
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), remained = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    remained++;
        
        int min = 0; // minute
        while (!q.empty() && remained)
        {
            min++;
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + DIR[j], ny = y + DIR[j+1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    remained--;
                    q.push({nx, ny});
                }
            }
        }
        return remained ? -1 : min;
    }
};
const int Solution::DIR[5] = { 0, 1, 0, -1, 0 };
// @lc code=end

