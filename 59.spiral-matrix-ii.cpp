/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0, j = 0, v = 1;
        n--;
        while (n > 0)
        {
            for (int k = 0; k < n; k++)
                ans[i][j++] = v++;
            for (int k = 0; k < n; k++)
                ans[i++][j] = v++;
            for (int k = 0; k < n; k++)
                ans[i][j--] = v++;
            for (int k = 0; k < n; k++)
                ans[i--][j] = v++;
            i++;
            j++;
            n -= 2;
        }
        if (n == 0)
            ans[i][j] = v;
        return ans;
    }
};
// @lc code=end

