/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    enum { UNVISITED, VISITING, VISITED };
    bool findOrder_helper(vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans, int node) {
        if (visited[node] == VISITING)
            return false;
        if (visited[node] == VISITED)
            return true;
        
        // visited[node] == UNVISITED
        visited[node] = VISITING;
        for (int neighbor : graph[node])
            if (!findOrder_helper(graph, visited, ans, neighbor))
                return false;
        visited[node] = VISITED;
        ans.push_back(node);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int>& prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        vector<int> ans, visited(numCourses, UNVISITED);
        for (int i = 0; i < numCourses; i++)
            if (!findOrder_helper(graph, visited, ans, i))
                return { };
        return ans;
    }
};
// @lc code=end

