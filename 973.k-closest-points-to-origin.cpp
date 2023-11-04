/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> heap(k, { INT_MAX, 0 }); // dist, ind
        for (int i = 0; i < points.size(); i++)
        {
            vector<int> vec = { points[i][0] * points[i][0] + points[i][1] * points[i][1], i };
            if (vec < heap.front())
            {
                pop_heap(heap.begin(), heap.end());
                heap.back() = vec;
                push_heap(heap.begin(), heap.end());
            }
        }
        for (vector<int>& vec : heap) // dist, ind -> point
            vec = points[vec[1]];
        return heap;
    }
};
// @lc code=end

