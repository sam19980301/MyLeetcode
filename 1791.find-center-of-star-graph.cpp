/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if (
            edges[0][0] == edges[1][0] ||
            edges[0][0] == edges[1][1]
        )
            return edges[0][0];
        return edges[0][1];
    }
};
// @lc code=end

