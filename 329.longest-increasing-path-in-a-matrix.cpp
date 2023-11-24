/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void longestIncreasingPath_helper(vector<vector<int>>& matrix, vector<vector<int>>& paths, int i, int j)
    {
        int m = matrix.size(), n = matrix[0].size(), curr = 1;
        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int k = 0; k < 4; k++)
        {
            int ni = i + DIR[k], nj = j + DIR[k+1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || matrix[ni][nj] <= matrix[i][j])
                continue;
            if (!paths[ni][nj])
                longestIncreasingPath_helper(matrix, paths, ni, nj);
            curr = max(curr, 1 + paths[ni][nj]);
        }
        paths[i][j] = curr;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> paths(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!paths[i][j])
                    longestIncreasingPath_helper(matrix, paths, i, j);
                ans = max(ans, paths[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end

