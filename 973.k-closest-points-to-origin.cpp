/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        auto euclidean_dist_less = [](const vector<int> &lhs, const vector<int> &rhs) -> bool {
            const int l0 = lhs.at(0);
            const int l1 = lhs.at(1);
            const int r0 = rhs.at(0);
            const int r1 = rhs.at(1);
            return (l0 * l0) + (l1 * l1) < (r0 * r0) + (r1 * r1);
        };

        vector<vector<int>> ans(points.begin(), points.begin() + k);
        ranges::make_heap(ans, euclidean_dist_less);
        auto it = points.begin() + k;
        while (it != points.end())
        {
            if (euclidean_dist_less(*it, ans.front()))
            {
                ranges::pop_heap(ans, euclidean_dist_less);
                ans.back() = *it;
                ranges::push_heap(ans, euclidean_dist_less);
            }
            it++;
        }
        return ans;
    }
};
// @lc code=end
