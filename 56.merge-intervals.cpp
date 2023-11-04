/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int>& curr = intervals[i];
            if (prev[1] < curr[0]) // non-overlap
            {
                ans.push_back(prev);
                prev = curr;
            }
            else // overlap
            {
                prev[1] = max(prev[1], curr[1]);
            }
        }
        ans.push_back(prev);
        return ans;
    }
};
// @lc code=end

