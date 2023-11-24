/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!mat[i][j])
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
        
        int dist = 1;
        while (!q.empty())
        {
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                auto [x, y] = q.front();
                q.pop();
                static const int DIR[5] = { 0, 1, 0, -1, 0 };
                for (int j = 0; j < 4; j++)
                {
                    int nx = x + DIR[j], ny = y + DIR[j+1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n || ans[nx][ny] <= dist)
                        continue;
                    q.push({nx, ny});
                    ans[nx][ny] = dist;
                }
            }
            dist++;
        }
        return ans;
    }
};
// @lc code=end

