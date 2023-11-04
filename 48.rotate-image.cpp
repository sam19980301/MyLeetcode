/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void rotate_helper(vector<vector<int>>& matrix, int start, int len) {
        if (len < 2)
            return ;
        
        int x[4] = { start, start + len - 1, start + len - 1, start };
        int y[4] = { start, start, start + len - 1, start + len - 1 };
        for (int i = 0; i < len - 1; i++)
        {
            swap(matrix[x[0]][y[0]++], matrix[x[1]][y[1]]);
            swap(matrix[x[1]--][y[1]], matrix[x[2]][y[2]]);
            swap(matrix[x[2]][y[2]--], matrix[x[3]++][y[3]]);
        }
        rotate_helper(matrix, start + 1, len - 2);
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        // alternative: diagonal + vertical flip
        rotate_helper(matrix, 0, matrix.size());
    }
};
// @lc code=end

