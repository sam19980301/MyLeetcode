/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void allPathsSourceTarget_helper(vector<vector<int>>& graph, vector<vector<int>>& ans ,vector<int>& path)
    {
        if (path.back() == graph.size() - 1)
        {
            ans.push_back(path);
            return ;
        }
        for (int node : graph[path.back()])
        {
            path.push_back(node);
            allPathsSourceTarget_helper(graph, ans, path);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        allPathsSourceTarget_helper(graph, ans, path);
        return ans;
    }
};
// @lc code=end

