/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // bfs topological sort (removing-leaf-first)
        if (n == 1)
            return { 0 };
        
        vector<vector<int>> graph(n, vector<int>());
        vector<int> degrees(n, 0);
        for (vector<int>& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1)
            {
                degrees[i]--;
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty())
        {
            ans.clear();
            int qs = q.size();
            for (int i = 0; i < qs; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (int neighbor : graph[node])
                {
                    if (--degrees[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        return ans;

        // // find the diameter nodes & get the "midpoint/center" of diameter
        // if (n == 0)
        //     return { };
        // if (n == 1)
        //     return { 0 };
        // if (n == 2)
        //     return { 0, 1 };

        // vector<vector<int>> graph(n, vector<int>());
        // for (vector<int>& edge : edges)
        // {
        //     graph[edge[0]].push_back(edge[1]);
        //     graph[edge[1]].push_back(edge[0]);
        // }

        // int dnode[2] { };

        // queue<int> q;
        // vector<int> parent(n, -1);
        // // first time bfs from any single node to find one of the diameter node
        // q.push(0);
        // parent[0] = 0;
        // while (!q.empty())
        // {
        //     int node = q.front();
        //     q.pop();
        //     for (int neighbor : graph[node])
        //     {
        //         if (parent[neighbor] == -1)
        //         {
        //             parent[neighbor] = node;
        //             dnode[0] = neighbor;
        //             q.push(neighbor);
        //         }
        //     }
        // }

        // // second time bfs from one of the diamter node to find another
        // for (int i = 0; i < n; i++)
        //     parent[i] = -1;
        // q.push(dnode[0]);
        // parent[dnode[0]] = dnode[0];
        // while (!q.empty())
        // {
        //     int node = q.front();
        //     q.pop();
        //     for (int neighbor : graph[node])
        //     {
        //         if (parent[neighbor] == -1)
        //         {
        //             parent[neighbor] = node;
        //             dnode[1] = neighbor;
        //             q.push(neighbor);
        //         }
        //     }
        // }

        // // calculate the diameter
        // int diameter = 0;
        // int node = dnode[1];
        // while (node != parent[node])
        // {
        //     node = parent[node];
        //     diameter++;
        // }

        // // find the midpoint/center
        // vector<int> ans;
        // int radius = diameter / 2;
        // node = dnode[1];
        // for (int i = 0; i < radius; i++)
        //     node = parent[node];
        // ans.push_back(node);
        // if (diameter % 2)
        //     ans.push_back(parent[node]);
        // return ans;
    }
};
// @lc code=end

