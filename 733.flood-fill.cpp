/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void floodFill_helper(vector<vector<int>>& image, int sr, int sc, int from_color, int to_color) {
        int m = image.size(), n = image[0].size();
        if (sr < 0 || sr >= m || sc < 0 || sc >= n) // out of boundary
            return ;
        
        int& color = image[sr][sc];
        if (color != from_color || color == to_color) // cannot flood or already flooded
            return ;
        color = to_color; // flood

        static const int DIR[5] = { 0, 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++)
            floodFill_helper(image, sr+DIR[i], sc+DIR[i+1], from_color, to_color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        floodFill_helper(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
// @lc code=end

