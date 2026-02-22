/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  private:
    static constexpr array<pair<int, int>, 4> dirs{make_pair(0, 1), make_pair(1, 0), make_pair(0, -1),
                                                   make_pair(-1, 0)};
    void floodFill_helper(vector<vector<int>> &image, int sr, int sc, int from_color, int to_color)
    {
        const size_t m = image.size();
        const size_t n = image.front().size();
        if (sr < 0 || cmp_greater_equal(sr, m) || sc < 0 || cmp_greater_equal(sc, n))
        {
            return;
        }

        int &pixel_value = image.at(sr).at(sc);
        if (pixel_value != from_color || pixel_value == to_color)
        {
            return;
        }
        pixel_value = to_color;

        for (auto [dr, dc] : dirs)
        {
            floodFill_helper(image, sr + dr, sc + dc, from_color, to_color);
        }
    }

  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        floodFill_helper(image, sr, sc, image.at(sr).at(sc), color);
        return image;
    }
};
// @lc code=end
