/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    static const int DIR[5];
    int largestIsland_helper(vector<vector<int>>& grid, int index, int r, int c)
    {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
            return 0;
        
        int area = 1;
        grid[r][c] = index;
        for (int i = 0; i < 4; i++)
            area += largestIsland_helper(grid, index, r + DIR[i], c + DIR[i+1]);
        return area;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> arr = { 0, 0 }; // index : area
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = largestIsland_helper(grid, arr.size(), i, j);
                    arr.push_back(area);
                    ans = max(ans, area);
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int sum = 1;
                    s.clear();
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + DIR[k], nj = j + DIR[k+1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n || !s.insert(grid[ni][nj]).second)
                            continue;
                        sum += arr[grid[ni][nj]];
                    }
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};
const int Solution::DIR[5] = { 0, 1, 0, -1, 0 };
// @lc code=end

