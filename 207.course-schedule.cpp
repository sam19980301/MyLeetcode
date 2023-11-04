/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    enum { UNVISITED, VISITING, VISITED };
    bool canFinish_helper(int n, vector<vector<int>>& graph, vector<int>& visit) { // dfs
        if (visit[n] == VISITED)
            return true;
        if (visit[n] == VISITING)
            return false;
        // visit[n] == UNVISITED
        visit[n] = VISITING;
        for (int neighbor : graph[n])
            if (!canFinish_helper(neighbor, graph, visit))
                return false;
        visit[n] = VISITED;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // construct graph
        vector<vector<int>> graph(numCourses);
        for (vector<int>& prerequisite : prerequisites)
            graph[prerequisite[0]].push_back(prerequisite[1]);

        // check cycle
        vector<int> visit(numCourses, UNVISITED);
        for (int i = 0; i < numCourses; i++)
            if (!canFinish_helper(i, graph, visit))
                return false;
        return true;
    }
};
// @lc code=end

