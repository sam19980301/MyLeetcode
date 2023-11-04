/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int DIR[5];
    void pacificAtlantic_helper(vector<vector<int>>& heights, vector<vector<bool>>& reachable, int x, int y) {
        if (reachable[x][y])
            return ;
        int m = heights.size(), n = heights[0].size();
        reachable[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + DIR[i], ny = y + DIR[i+1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || heights[x][y] > heights[nx][ny])
                continue;
            pacificAtlantic_helper(heights, reachable, nx, ny);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p_reachable(m, vector<bool>(n, false)), a_reachable(p_reachable);
        for (int i = 0; i < m; i++)
            pacificAtlantic_helper(heights, p_reachable, i, 0);
        for (int i = 0; i < n; i++)
            pacificAtlantic_helper(heights, p_reachable, 0, i);
        for (int i = 0; i < m; i++)
            pacificAtlantic_helper(heights, a_reachable, i, n - 1);
        for (int i = 0; i < n; i++)
            pacificAtlantic_helper(heights, a_reachable, m - 1, i);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (p_reachable[i][j] && a_reachable[i][j])
                    ans.push_back({ i, j });
        return ans;
    }
};
const int Solution::DIR[5] = { 0, 1, 0, -1, 0 };
// @lc code=end

